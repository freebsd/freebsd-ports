# New ports collection makefile for:	Wanderlust (for emacs)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	wanderlust
PORTVERSION=	1.1.0
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/wanderlust/stable/ \
		ftp://daidai.kuis.kyoto-u.ac.jp/pub/mirror/ftp.gohome.org/pub/elisp/wl/stable/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	wl-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

SEMI_VER=	1.13.7
SEMI_COOKIE=	semi-${EMACS_PORT_NAME}-${SEMI_VER}.FreeBSD-packages

.if !defined (IS_SLAVE)
# for emacs19
EMACS_NAME=		emacs
EMACS_PORT_NAME=	emacs
EMACS_VER=		19.34
EMACS_LIBDIR=		share/emacs
EMACS_LIBDIR_WITH_VER=	share/emacs/${EMACS_VER}
.endif

EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}

BUILD_DEPENDS= 	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}

.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	no
.endif
.if (${HAVE_COMMON_PORT} == "yes")
# depends on common port
RUN_DEPENDS=	${PKG_DBDIR}/${EMACS_PORT_NAME:S/xemacs21-mule/xemacs-mule/}-common-${MULE_VER}:${PORTSDIR}/editors/${EMACS_PORT_NAME}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT_NAME}
.endif
# depends on semi
BUILD_DEPENDS+=	${PREFIX}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi-${EMACS_PORT_NAME}-current
RUN_DEPENDS+=	${PREFIX}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi-${EMACS_PORT_NAME}-current

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
.endif
.if (${EMACS_PORT_NAME} == "emacs20" || ${EMACS_PORT_NAME} == "mule")
ALL_TARGET=	all info
.endif

.if !defined(WITH_IM) && exists(${LOCALBASE}/bin/imput)
WITH_IM=	yes
.endif

.if defined(WITH_IM) && ${WITH_IM} == yes
BUILD_DEPENDS+=	imput:${PORTSDIR}/mail/im
RUN_DEPENDS+=	imput:${PORTSDIR}/mail/im
.endif

DIRSECTION=	"The Emacs editor and associated tools"
DOCSDIR=	${PREFIX}/share/doc/wanderlust
DOCS=		00README 00README.ja ChangeLog ChangeLog.ja
SAMPLESDIR=	${PREFIX}/share/examples/wanderlust/en
SAMPLESDIR_JA=	${PREFIX}/share/examples/wanderlust/ja
SAMPLES=	dot.addresses dot.wl dot.folders

PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} DIRSECTION=${DIRSECTION}

PLISTORIG=	${PKGDIR}/PLIST.${EMACS_PORT_NAME}
PLIST=		${WRKDIR}/PLIST

MAKE_ARGS=	EMACS=${EMACS_CMD} LISPDIR=${PREFIX}/${EMACS_LIBDIR}/site-lisp \
		FLAGS="-batch -q -no-site-file -l ${WRKDIR}/wanderlust-startup.el"
.if (${EMACS_PORT_NAME} == "xemacs20") || (${EMACS_PORT_NAME} == "xemacs21-mule")
MAKE_ARGS+=	XEMACS=${EMACS_CMD}
.endif
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
MAKE_ARGS+=	PACKAGEDIR=${PREFIX}/${EMACS_PACKAGESDIR}
.else
MAKE_ARGS+=	INFODIR=${PREFIX}/info
.endif

post-configure:
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACS_LIBDIR%%,${EMACS_LIBDIR},g" \
		-e "s,%%EMACS_LIBDIR_WITH_VER%%,${EMACS_LIBDIR_WITH_VER},g" \
		-e "s,%%EMACS_PACKAGESDIR%%,${EMACS_PACKAGESDIR},g" \
		< ${FILESDIR}/wanderlust-startup.${EMACS_PORT_NAME}.el.tmpl > ${WRKDIR}/wanderlust-startup.el

pre-build:
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

pre-install:
.if (${EMACS_PORT_NAME} != "xemacs21-mule")
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
.endif
.if defined(WITH_IM) && ${WITH_IM} == yes
	@${CAT} ${PLISTORIG} > ${PLIST}
.else
	@${GREP} -vw 'im-wl\.elc\?' ${PLISTORIG} > ${PLIST}
.endif

post-install:
	@${MAKE} install-info
.if !defined(NOPORTDOCS)
	@${MAKE} install-docs
.endif
.if (${EMACS_PORT_NAME} == "xemacs20")
	@${MAKE} install-icons
.endif
	@${MAKE} install-samples
	@${MAKE} install-utils
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	@${MAKE} install-manifest
.endif
	@${CAT} ${PKGDIR}/MESSAGE

# local targets
install-info:
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	@if [ ! -f ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir; \
	fi
	@install-info --section=${DIRSECTION} ${PREFIX}/${EMACS_PACKAGESDIR}/info/wl-ja.info ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir
.endif
.if (${EMACS_PORT_NAME} == "emacs20" || ${EMACS_PORT_NAME} == "mule")
	@${INSTALL_DATA} ${WRKSRC}/doc/wl-ja.info ${PREFIX}/info
	@install-info --section=${DIRSECTION} ${PREFIX}/info/wl-ja.info ${PREFIX}/info/dir
.endif

install-docs:
	@${MKDIR} ${DOCSDIR}
	@for i in ${DOCS} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR} ; \
	done
	@${INSTALL_DATA} ${WRKSRC}/doc/wl-ja.texi ${DOCSDIR}

install-icons:
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/etc/wl
	@(cd ${WRKSRC}/etc/icons ; \
	for i in *.xpm ; do \
		${INSTALL_DATA} $$i ${PREFIX}/${EMACS_LIBDIR}/etc/wl ; \
	done)

install-samples:
	@${MKDIR} ${SAMPLESDIR}
	@${MKDIR} ${SAMPLESDIR_JA}
	@for i in ${SAMPLES} ; do \
	${INSTALL_DATA} ${WRKSRC}/samples/en/$$i ${SAMPLESDIR} ; \
	${INSTALL_DATA} ${WRKSRC}/samples/ja/$$i ${SAMPLESDIR_JA} ; \
	done

install-utils:
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/bbdb-wl.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/rfc2368.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/ssl.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/wl-mailto.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
.else
.if (${EMACS_PORT_NAME} == "emacs" || ${EMACS_PORT_NAME} == "mule")
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.if (${EMACS_PORT_NAME} == "emacs")
	@${INSTALL_DATA} ${WRKDIR}/wl-${PORTVERSION}/wl-mule.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
.endif
.else
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif
	@${INSTALL_DATA} ${WRKSRC}/utils/bbdb-wl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/rfc2368.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/ssl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/wl-mailto.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wl
.endif

install-manifest:
	@${CAT} ${PKGDIR}/PLIST.${EMACS_PORT_NAME} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s!^%%EMACS_PACKAGESDIR%%!!" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} ${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/
	@${INSTALL_DATA} ${FILESDIR}/_pkg.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl

.include <bsd.port.mk>
