# New ports collection makefile for:	T-gnus (for emacs21)
# Date created:		13 September 2000
# Whom: 		Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t-gnus
PORTVERSION=	${TGNUSVERSION:S/_/./g:S/-/./g}
PORTREVISION=	1
CATEGORIES=	news mail elisp
MASTER_SITES=	http://www.jpl.org/elips/t-gnus-6.16/snapshots/ \
		http://cvs.m17n.org/archives/gnus/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-${TGNUSVERSION}

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	I18N Gnus using SEMI, which provides MIME capabilities

BUILD_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

USE_AUTOCONF=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

TGNUSVERSION=	6_16_2-02
EMACS_PORT_NAME?=emacs21
EMACS_W3M_PORT_NAME?=	emacs-w3m
EMACS_W3M_LISP_FILE?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/w3m/shimbun.el

.include <bsd.port.pre.mk>

.if exists(${EMACS_W3M_LISP_FILE})
BUILD_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
RUN_DEPENDS+=	${EMACS_W3M_LISP_FILE}:${PORTSDIR}/www/${EMACS_W3M_PORT_NAME}
SHIMBUN=	""
.else
SHIMBUN=	"@comment "
.endif

.if (${EMACS_PORT_NAME} == "mule")
MIMEUI_VERSION=	1.13
MIMEUI_PRODUCT=	semi113
.else # emacs21, emacs20, xemacs21 or xemacs21-mule
MIMEUI_VERSION=	1.14
MIMEUI_PRODUCT=	semi
.endif
.if (${EMACS_PORT_NAME} == "emacs21")
MIMEUI_PORT_NAME=	${MIMEUI_PRODUCT}
.else
MIMEUI_PORT_NAME=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}
.endif
MIMEUI_COOKIE=		semi-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

.if (${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule")
MANIFEST=		MANIFEST.t-gnus
EMACS_PACKAGESDIR=	lib/xemacs/site-packages
CONFIGURE_ARGS=	--with-xemacs=${EMACS_CMD} --with-packagedir=${LOCALBASE}/${EMACS_PACKAGESDIR}
BUILD_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/mh-e/mh-e.el:${PORTSDIR}/editors/xemacs-packages \
		${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/bbdb/bbdb.el:${PORTSDIR}/editors/xemacs-packages
RUN_DEPENDS+=	${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/mh-e/mh-e.el:${PORTSDIR}/editors/xemacs-packages \
		${LOCALBASE}/${EMACS_LIBDIR}/xemacs-packages/lisp/bbdb/bbdb.el:${PORTSDIR}/editors/xemacs-packages
INFODIR=	${LOCALBASE}/${EMACS_PACKAGESDIR}/info
STARTUPDIR=	${EMACS_PACKAGESDIR}/lisp
INFOFILES=	emacs-mime gnus gnus-ja message message-ja sieve
.if (${EMACS_PORT_NAME} == "xemacs21")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
.elif (${EMACS_PORT_NAME} == "xemacs21-mule")
ALL_TARGET=	package-ja
INSTALL_TARGET=	install-package-ja
.endif
.else  # emacs21, emacs20 or mule
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/t-gnus \
		--infodir=${INFODIR}
ALL_TARGET=	all-ja
INSTALL_TARGET=	install-ja
INFODIR=	${LOCALBASE}/info
STARTUPDIR=	${EMACS_VERSION_SITE_LISPDIR}
.endif

DIRSECTION=	"The Emacs editor and associated tools"
PORTDOCDIR=	share/doc/t-gnus-${EMACS_PORT_NAME}
DOCS=		ChangeLog ChangeLog.1 ChangeLog.2 ChangeLog.3 GNUS-NEWS Mule23@1934.en Mule23@1934.ja README-gnus-bbdb.en README-gnus-bbdb.ja README-offline.en README-offline.ja README.T-gnus README.branch README.branch.ja README.semi README.semi.ja TODO.ja
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		DIRSECTION=${DIRSECTION} \
		EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${LOCALBASE}\///} \
		EMACS_VERSION_SITE_LISPDIR=${EMACS_VERSION_SITE_LISPDIR} \
		SHIMBUN=${SHIMBUN}
PLIST=		${PKGDIR}/pkg-plist.${EMACS_PORT_NAME}

.if (${EMACS_PORT_NAME} == "mule")
post-extract:
	${ECHO_CMD} "${EMACS_CMD} -l apel-setupel.el \$$@" > ${WRKDIR}/mule-apel
	${CHMOD} +x ${WRKDIR}/mule-apel
.endif

post-configure:
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACS_LIBDIR%%,${EMACS_LIBDIR},g" \
		-e "s,%%EMACS_LIBDIR_WITH_VER%%,${EMACS_LIBDIR_WITH_VER},g" \
		-e "s,%%EMACS_PACKAGESDIR%%,${EMACS_PACKAGESDIR},g" \
		< ${FILESDIR}/t-gnus-startup.${EMACS_PORT_NAME}.el.tmpl > ${WRKDIR}/t-gnus-startup.el

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKDIR}/t-gnus-startup.el ${LOCALBASE}/${STARTUPDIR}
# For XEmacs, ${INFODIR}/dir is not necessary. So these were deleted.
.if (${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule")
.for file in ${INFOFILES}
	 install-info --delete ${INFODIR}/${file} ${INFODIR}/dir
.endfor
	if [ `${GREP} '^*' ${INFODIR}/dir | wc -l` -eq 1 ]; then \
		${RM} ${INFODIR}/dir; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.if (${EMACS_PORT_NAME} == "mule")
MAKE_ARGS+=	EMACS="${WRKDIR}/mule-apel"  XEMACS="${WRKDIR}/mule-apel"
.endif

.include <bsd.port.post.mk>
