# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wanderlust
PORTVERSION=	2.15.9.b.${SNAPDATE}
PORTREVISION=	1
CATEGORIES=	mail elisp
PKGNAMESUFFIX=	-devel-${EMACS_PORT_NAME}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Yet another message interface on Emacsen

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_EMACS=	yes
USE_GITHUB=	yes

GH_TAGNAME=	770d54f

SNAPDATE=	20170628

CONFLICTS=	wanderlust-*-2.14.*

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.pre.mk>
.include <bsd.port.options.mk>

MIMEUI_PORT_NAME=	${MIMEUI_PRODUCT}
MIMEUI_PRODUCT=	semi
MIMEUI_VERSION=	1.14
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

BUILD_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:editors/${MIMEUI_PORT_NAME}

.if (${EMACS_NAME} == "emacs") && (${EMACS_MAJOR_VER} >= 22)
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/x-face-e21.el:mail/x-face-e21
.endif

EMACS_W3M_PORT_NAME=	emacs-w3m
EMACS_W3M_LISP_FILE=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/shimbun.el

.if exists(${EMACS_W3M_LISP_FILE})
BUILD_DEPENDS+=	${EMACS_W3M_LISP_FILE}:www/${EMACS_W3M_PORT_NAME}
RUN_DEPENDS+=	${EMACS_W3M_LISP_FILE}:www/${EMACS_W3M_PORT_NAME}
SHIMBUN=	""
.else
SHIMBUN=	"@comment "
.endif

INFODIR=	${PREFIX}/info
INFO=		wl wl-ja
UTILSDIR=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/wl
WL_ICONDIR=	${EMACS_LIBDIR_WITH_VER}/etc/wl/icons
STARTUPDIR=	${EMACS_VERSION_SITE_LISPDIR}

DOCSDIR_JA=	${PREFIX}/share/doc/ja/wanderlust
DOCS=		README.md NEWS doc/wl.texi
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
		LISPDIR=${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} \
		INFODIR=${STAGEDIR}${INFODIR} \
		PIXMAPDIR=${STAGEDIR}${PREFIX}/${EMACS_LIBDIR_WITH_VER}/etc/wl/icons \
		FLAGS="-batch -q -no-site-file"

post-extract:
	@${CP} ${FILESDIR}/WL-CFG ${WRKSRC}

post-configure:
	${REINPLACE_CMD} -e 's|%%EMACS_LIBDIR_WITH_VER%%|${PREFIX}/${EMACS_LIBDIR_WITH_VER}|' ${WRKSRC}/WL-MK

post-install:
.if !exists(${EMACS_W3M_LISP_FILE})
	${INSTALL_DATA} ${WRKSRC}/elmo/elmo-shimbun.el ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/wl
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MAKE} install-docs
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MAKE} install-examples
.endif
	@${MAKE} install-utils

# local targets
install-docs:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR_JA}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.for i in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR_JA}
.endfor

install-examples:
.for l in ${EXAMPLESLANG}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/$l
	for i in ${EXAMPLES} ; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$l/$$i ${STAGEDIR}${EXAMPLESDIR}/$l; \
	done
.endfor
	${INSTALL_DATA} ${WRKSRC}/etc/ja.Emacs ${STAGEDIR}${EXAMPLESDIR}/ja

install-utils:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${UTILSDIR}
.for i in ${UTILS}
	${INSTALL_DATA} ${WRKSRC}/utils/${i} ${STAGEDIR}${PREFIX}/${UTILSDIR}
.endfor
	@${MKDIR} ${PREFIX}/${STARTUPDIR}
	@${INSTALL_DATA} ${FILESDIR}/wanderlust-startup.el ${STAGEDIR}${PREFIX}/${STARTUPDIR}

.include <bsd.port.post.mk>
