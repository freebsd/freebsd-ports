# New ports collection makefile for:	T-gnus (for emacs)
# Date created:		13 September 2000
# Whom: 		Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	t-gnus
PORTVERSION=	${TGNUSVERSION:S/_/./g:S/-/./g}
CATEGORIES=	news mail elisp
MASTER_SITES=	http://www.jpl.org/elips/t-gnus-6.14/snapshots/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-${TGNUSVERSION}

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
TGNUSVERSION=	6_14_6-04
MIMEUI_PRODUCT?=semi
MIMEUI_VERSION?=1.13.7
MIMEUI_PORT_NAME?=${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-current
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

EMACS_PORT_NAME?=emacs20

.if (${EMACS_PORT_NAME} == "emacs20" || ${EMACS_PORT_NAME} == "mule" || \
	${EMACS_PORT_NAME} == "xemacs21-mule")
WITH_MULE=yes
.else
WITHOUT_MULE=yes
.endif

.if (${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule")
CONFIGURE_ARGS=	--with-xemacs=${EMACS_CMD} --with-packagedir=${LOCALBASE}/${EMACS_PACKAGESDIR}
.else
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/t-gnus \
		--infodir=${INFODIR}
.endif

.if defined(EMACS_PACKAGESDIR)
INFODIR=	${LOCALBASE}/${EMACS_PACKAGESDIR}/info
STARTUPDIR=	${EMACS_PACKAGESDIR}/lisp
INFOFILES=	emacs-mime gnus gnus-ja message message-ja
.if (${EMACS_PORT_NAME} == "xemacs21")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
.elif (${EMACS_PORT_NAME} == "xemacs21-mule")
ALL_TARGET=	package-ja
INSTALL_TARGET=	install-package-ja
.endif
.elif (${EMACS_PORT_NAME} == "emacs20" || ${EMACS_PORT_NAME} == "mule")
ALL_TARGET=	all-ja
INSTALL_TARGET=	install-ja
INFODIR=	${LOCALBASE}/info
STARTUPDIR=	${EMACS_SITE_LISPDIR}
.endif

DIRSECTION=	"The Emacs editor and associated tools"
PORTDOCDIR=	share/doc/t-gnus-${EMACS_PORT_NAME}
DOCS=		ChangeLog ChangeLog.1 ChangeLog.2 GNUS-NEWS Mule23@1934.en Mule23@1934.ja README README-gnus-bbdb.en README-gnus-bbdb.ja README-offline.en README-offline.ja README.T-gnus README.branch README.branch.ja README.semi README.semi.ja TODO.ja
PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		DIRSECTION=${DIRSECTION} \
		EMACS_PORT_NAME=${EMACS_PORT_NAME} \
		INFODIR=${INFODIR:S/${LOCALBASE}\///} \
		EMACS_SITE_LISPDIR=${EMACS_SITE_LISPDIR}
PLIST=		${PKGDIR}/pkg-plist.${EMACS_PORT_NAME}

.if (${EMACS_PORT_NAME} == "mule")
post-extract:
	${ECHO} "${EMACS_CMD} -l apel-setupel.el \$$@" > ${WRKDIR}/mule-apel
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
	${INSTALL_DATA} ${WRKDIR}/t-gnus-startup.el ${PREFIX}/${STARTUPDIR}
# For XEmacs, ${INFODIR}/dir is not necessary.
.if (${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule")
.for file in ${INFOFILES}
	 install-info --delete ${INFODIR}/${file} ${INFODIR}/dir
.endfor
	if [ `${GREP} '^*' ${INFODIR}/dir | wc -l` -eq 1 ]; then \
		${RM} ${INFODIR}/dir; \
	fi
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "mule")
MAKE_ARGS+=	EMACS="${WRKDIR}/mule-apel"  XEMACS="${WRKDIR}/mule-apel"
.endif

.include <bsd.port.post.mk>
