# New ports collection makefile for:   emacs-w3m
# Date Created:			24 Mar 2001
# Whom:				MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	emacs-w3m
PORTVERSION=	1.3.1
CATEGORIES=	www elisp
MASTER_SITES=	http://emacs-w3m.namazu.org/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	w3m_el-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org

EMACS_PORT_NAME?=	emacs21

CONFIGURE_ARGS?=	--with-emacs=${EMACS_CMD} \
			--with-lispdir=${PREFIX}/${LISPDIR} \
			--with-icondir=${PREFIX}/${ICONDIR}
LISPDIR?=	${EMACS_VERSION_SITE_LISPDIR}/w3m
ICONDIR?=	${EMACS_LIBDIR_WITH_VER}/etc/w3m/icons
ETCDIR?=	${EMACS_LIBDIR_WITH_VER}/etc/w3m
PKGINFODIR?=	"@comment "

USE_AUTOCONF=	yes
ALL_TARGET=	default

PLIST_SUB+=	EMACS_NAME=${EMACS_NAME} \
		XEMACS=${XEMACS} \
		EMACS20=${EMACS20} \
		EMACS21=${EMACS21} \
		EMACS=${EMACS} \
		LISPDIR=${LISPDIR} \
		ICONDIR=${ICONDIR} \
		ETCDIR=${ETCDIR} \
		PKGINFODIR=${PKGINFODIR} \
		ICONS=${ICONS} \
		ETC=${ETC}

DOCS=		FAQ README
DOCS_JA=	FAQ.ja README.ja README.namazu.ja README.shimbun.ja TIPS.ja

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}
DOCSDIR_JA=	${PREFIX}/share/doc/ja/${PORTNAME}

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
XEMACS=		""
EMACS=		"@comment "
EMACS20=	"@comment "
EMACS21=	"@comment "
ICONS=		""
ETC=		"@comment "
.else
.if (${EMACS_PORT_NAME} == "emacs20")
XEMACS=		"@comment "
EMACS=		""
EMACS20=	""
EMACS21=	"@comment "
ICONS=		"@comment "
ETC=		"@comment "
.else
XEMACS=		"@comment "
EMACS=		""
EMACS20=	"@comment "
EMACS21=	""
ICONS=		""
ETC=		""
INSTALL_TARGET=	install install-icons
.endif
.endif

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs21")
FLIM_PORT=	${PORTSDIR}/editors/flim
SEMI_PORT=	${PORTSDIR}/editors/semi
MULE_UCS_PORT=	${PORTSDIR}/converters/mule-ucs
.endif

FLIM_TRUNK=	1.14
FLIM_COOKIE=	${LOCALBASE}/share/flim/flim-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
FLIM_PORT?=	${PORTSDIR}/editors/flim-${EMACS_PORT_NAME}

SEMI_TRUNK=	1.14
SEMI_COOKIE=	${LOCALBASE}/share/semi/semi-${EMACS_PORT_NAME}-${FLIM_TRUNK}.FreeBSD-packages
SEMI_PORT?=	${PORTSDIR}/editors/semi-${EMACS_PORT_NAME}

MULE_UCS_PORT?=	${PORTSDIR}/converters/mule-ucs-${EMACS_PORT_NAME}
MULE_UCS_ELISP_FILE=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/mule-ucs/un-define.el

BUILD_DEPENDS=	w3m:${PORTSDIR}/www/w3m-m17n \
		${FLIM_COOKIE}:${FLIM_PORT}
RUN_DEPENDS=	w3m:${PORTSDIR}/www/w3m-m17n \
		${FLIM_COOKIE}:${FLIM_PORT}
.if (${EMACS_PORT_NAME} != "xemacs21-mule" && !defined(WITHOUT_OCTET_VIEWER))
RUN_DEPENDS+=	${SEMI_COOKIE}:${SEMI_PORT} \
		wvHtml:${PORTSDIR}/textproc/wv \
		xlhtml:${PORTSDIR}/textproc/xlhtml \
		${MULE_UCS_ELISP_FILE}:${MULE_UCS_PORT}
.endif

pre-everything::
.if (${EMACS_PORT_NAME} != "xemacs21-mule" || !defined(WITHOUT_OCTET_VIEWER))
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===>  If you don't use octet stream viewer,"
	@${ECHO_MSG} "===>  please define WITHOUT_OCTET_VIEWER."
	@${ECHO_MSG} "===>"
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
