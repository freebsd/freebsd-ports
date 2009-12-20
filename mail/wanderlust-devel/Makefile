# New ports collection makefile for:	Wanderlust
# Date created:		26 Sep 2009
# Whom: 		MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wanderlust
PORTVERSION=	2.15.7.b.${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	mail elisp
MASTER_SITES=	http://people.freebsd.org/~nobutaka/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	wanderlust-cvs-snap-${SNAPDATE}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Yet another message interface on Emacsen

USE_BZIP2=	yes
USE_EMACS=	yes

SNAPDATE=	20090926

CONFLICTS=	wanderlust-*-2.14.*
NO_LATEST_LINK=	yes

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs23")
BROKEN=     can not be installed with Emacs 23
.endif

MIMEUI_PORT_NAME=	${MIMEUI_PRODUCT}
MIMEUI_PRODUCT=	semi
MIMEUI_VERSION=	1.14
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

BUILD_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

.if (${EMACS_NAME} == "emacs") && (${EMACS_MAJOR_VER} >= 22)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/x-face-e21.el:${PORTSDIR}/mail/x-face-e21
.endif

EMACS_W3M_PORT_NAME=	emacs-w3m
EMACS_W3M_LISP_FILE=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/shimbun.el

.if exists(${EMACS_W3M_LISP_FILE})
BUILD_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
RUN_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
SHIMBUN=	""
.else
SHIMBUN=	"@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}
INFODIR=	${PREFIX}/info
INFO=		wl wl-ja
UTILSDIR=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_ICONDIR=	${EMACS_LIBDIR_WITH_VER}/etc/wl/icons
STARTUPDIR=	${EMACS_VERSION_SITE_LISPDIR}

DOCSDIR_JA=	${PREFIX}/share/doc/ja/wanderlust
DOCS=		README NEWS doc/wl.texi
DOCS_JA=	README.ja NEWS.ja doc/wl-ja.texi
EXAMPLESLANG=	en ja
EXAMPLES=	dot.addresses dot.folders dot.wl
UTILS=		bbdb-wl.el

PLIST_SUB+=	DIRSECTION=${DIRSECTION} \
		STARTUPDIR=${STARTUPDIR} \
		WL_LISPDIR=${WL_LISPDIR} \
		WL_ICONDIR=${WL_ICONDIR} \
		SHIMBUN=${SHIMBUN} \
		DOCSDIR_JA=${DOCSDIR_JA:S,^${PREFIX}/,,}

PLIST=		${PKGDIR}/pkg-plist
MAKE_ARGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD} \
		LISPDIR=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		FLAGS="-batch -q -no-site-file" \
		INFODIR=${INFODIR}

post-extract:
	@${CP} ${FILESDIR}/WL-CFG ${WRKSRC}

post-install:
.if !exists(${EMACS_W3M_LISP_FILE})
	${INSTALL_DATA} ${WRKSRC}/elmo/elmo-shimbun.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/wl
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} install-docs
.endif
.if !defined(NOPORTEXAMPLES)
	@${MAKE} install-examples
.endif
	@${MAKE} install-utils
	@${CAT} ${PKGMESSAGE}

# local targets
install-docs:
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${DOCSDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR_JA}
.endfor

install-examples:
.for l in ${EXAMPLESLANG}
	${MKDIR} ${EXAMPLESDIR}/$l
	for i in ${EXAMPLES} ; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$l/$$i ${EXAMPLESDIR}/$l; \
	done
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/ja.Emacs ${EXAMPLESDIR}/ja

install-utils:
	@${MKDIR} ${PREFIX}/${UTILSDIR}
.for i in ${UTILS}
	${INSTALL_DATA} ${WRKSRC}/utils/${i} ${PREFIX}/${UTILSDIR}
.endfor
	@${MKDIR} ${PREFIX}/${STARTUPDIR}
	@${INSTALL_DATA} ${FILESDIR}/wanderlust-startup.el ${PREFIX}/${STARTUPDIR}

.include <bsd.port.post.mk>
