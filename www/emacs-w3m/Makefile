# New ports collection makefile for:   emacs-w3m
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs-w3m
PORTVERSION=	1.2.4
CATEGORIES=	www elisp
MASTER_SITES=	http://emacs-w3m.namazu.org/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	w3m_el-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

EMACS_PORT_NAME?=	emacs21

CONFIGURE_ARGS?=	--with-emacs=${EMACS_CMD} \
			--with-lispdir=${PREFIX}/${LISPDIR}
LISPDIR?=	${EMACS_VERSION_SITE_LISPDIR}/w3m
ICONDIR?=	${EMACS_LIBDIR_WITH_VER}/etc/w3m/icons
ETCDIR?=	${EMACS_LIBDIR_WITH_VER}/etc/w3m
PKGINFODIR?=	"@comment "

USE_AUTOCONF=	yes
ALL_TARGET=	default

PLIST_SUB+=	EMACS_NAME=${EMACS_NAME} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		EMACS20_ONLY=${EMACS20_ONLY} \
		EMACS21_ONLY=${EMACS21_ONLY} \
		EMACS_ONLY=${EMACS_ONLY} \
		LISPDIR=${LISPDIR} \
		ICONDIR=${ICONDIR} \
		ETCDIR=${ETCDIR} \
		PKGINFODIR=${PKGINFODIR} \
		SHIMBUN=${SHIMBUN} \
		ICONS=${ICONS} \
		ETC=${ETC}

DOCS=		FAQ README
DOCS_JA=	FAQ.ja README.ja README.namazu.ja README.shimbun.ja TIPS.ja

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
DOCSDIR_JA=	${PREFIX}/share/doc/ja/${PORTNAME}

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
XEMACS_ONLY=	""
EMACS_ONLY=	"@comment "
EMACS20_ONLY=	"@comment "
EMACS21_ONLY=	"@comment "
ICONS=		""
ETC=		"@comment "
.else
.if (${EMACS_PORT_NAME} == "emacs20")
XEMACS_ONLY=	"@comment "
EMACS_ONLY=	""
EMACS20_ONLY=	""
EMACS21_ONLY=	"@comment "
ICONS=		"@comment "
ETC=		"@comment "
.else
XEMACS_ONLY=	"@comment "
EMACS_ONLY=	""
EMACS20_ONLY=	"@comment "
EMACS21_ONLY=	""
ICONS=		""
ETC=		""
INSTALL_TARGET=	install install-icons
.endif
.endif

.include <bsd.port.pre.mk>

FLIM_TRUNK=	1.14
FLIM_COOKIE=	${LOCALBASE}/share/flim/flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
.if (${EMACS_PORT_NAME} == "emacs21")
FLIM_PORT=	${PORTSDIR}/editors/flim
.else
FLIM_PORT=	${PORTSDIR}/editors/flim-${EMACS_PORT_NAME}
.endif

.if defined(WITH_SHIMBUN)
HAVE_FLIM=	yes
SHIMBUN=	""
.else
.if exists(${FLIM_COOKIE})
HAVE_FLIM=	yes
SHIMBUN=	""
.else
SHIMBUN=	"@comment "
.endif
.endif

.if defined(HAVE_FLIM)
BUILD_DEPENDS+=	${FLIM_COOKIE}:${FLIM_PORT}
RUN_DEPENDS+=		${FLIM_COOKIE}:${FLIM_PORT}
.endif
BUILD_DEPENDS+=	w3m:${PORTSDIR}/www/w3m-m17n
RUN_DEPENDS+=		w3m:${PORTSDIR}/www/w3m-m17n

.if !defined(HAVE_FLIM)
pre-fetch:
	@${ECHO_MSG}
	@${ECHO_MSG} "NOTE: You can have shimbun support by adding \"WITH_SHIMBUN=yes\" to argument of make."
	@${ECHO_MSG}
.endif

post-extract:
.if defined(EMACS_PACKAGESDIR)
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${MKDIR} ${DOCSDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR_JA}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
