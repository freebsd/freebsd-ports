# New ports collection makefile for:	Wanderlust (for emacs)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	wanderlust-${EMACS_PORT}
PORTVERSION=	1.0.3
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/wanderlust/stable/ \
		ftp://daidai.kuis.kyoto-u.ac.jp/pub/mirror/ftp.gohome.org/pub/elisp/wl/stable/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/
DISTNAME=	wl-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

SEMI_VER=	1.13.4
SEMI_COOKIE=	semi-${EMACS_PORT}-${SEMI_VER}.FreeBSD-packages

.if !defined (IS_SLAVE)
# for emacs19
EMACS_NAME=		emacs
EMACS_PORT=		emacs
EMACS_VER=		19.34
EMACS_LIBDIR=		share/emacs
EMACS_LIBDIR_WITH_VER=	share/emacs/${EMACS_VER}
.endif

EMACS_CMD=	${PREFIX}/bin/${EMACS_NAME}-${EMACS_VER}

BUILD_DEPENDS= 	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}

.if !defined(HAVE_COMMON_PORT)
HAVE_COMMON_PORT=	no
.endif
.if (${HAVE_COMMON_PORT} == "yes")
# depends on common port
RUN_DEPENDS=	${PKG_DBDIR}/${EMACS_PORT}-common-${MULE_VER}:${PORTSDIR}/editors/${EMACS_PORT}-common
.else
RUN_DEPENDS=	${EMACS_CMD}:${PORTSDIR}/editors/${EMACS_PORT}
.endif
# depends on semi
BUILD_DEPENDS+=	${PREFIX}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/share/semi/${SEMI_COOKIE}:${PORTSDIR}/editors/semi-${EMACS_PORT}

.if (${EMACS_PORT} == "xemacs21-mule")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
.endif
.if (${EMACS_PORT} == "emacs20" || ${EMACS_PORT} == "mule")
ALL_TARGET=	all info
.endif

DIRSECTION=	"The Emacs editor and associated tools"
DOCSDIR=	${PREFIX}/share/doc/wanderlust
DOCS=		00README 00README.ja ChangeLog ChangeLog.ja
SAMPLESDIR=	${PREFIX}/share/examples/wanderlust
SAMPLES=	sample.addresses sample.dot.wl sample.folders

PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} DIRSECTION=${DIRSECTION}

PLIST=		${PKGDIR}/PLIST.${EMACS_PORT}
MAKE_ARGS=	EMACS=${EMACS_CMD} ELISPDIR=${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust \
		FLAGS="-batch -q -no-site-file -l ${WRKDIR}/wanderlust-startup.el"
.if (${EMACS_PORT} == "xemacs21-mule")
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
		< ${FILESDIR}/wanderlust-startup.${EMACS_PORT}.el.tmpl > ${WRKDIR}/wanderlust-startup.el

pre-build:
.if (${EMACS_PORT} == "xemacs21-mule")
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}/
.endif

pre-install:
.if (${EMACS_PORT} != "xemacs21-mule")
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
.endif

post-install:
	@${MAKE} install-info
.if !defined(NOPORTDOCS)
	@${MAKE} install-docs
.endif
.if (${EMACS_PORT} == "xemacs20")
	@${MAKE} install-icons
.endif
	@${MAKE} install-samples
	@${MAKE} install-utils
.if (${EMACS_PORT} == "xemacs21-mule")
	@${MAKE} install-manifest
.endif
	@${CAT} ${PKGDIR}/MESSAGE

# local targets
install-info:
.if (${EMACS_PORT} == "xemacs21-mule")
	@if [ ! -f ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir; \
	fi
	@install-info --section=${DIRSECTION} ${PREFIX}/${EMACS_PACKAGESDIR}/info/wl-ja.info ${PREFIX}/${EMACS_PACKAGESDIR}/info/dir
.endif
.if (${EMACS_PORT} == "emacs20" || ${EMACS_PORT} == "mule")
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
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/etc/wanderlust
	@for i in *.xpm ; do \
		${INSTALL_DATA} ${WRKSRC}/etc/$$i ${PREFIX}/${EMACS_LIBDIR}/etc/wanderlust ; \
	done

install-samples:
	@${MKDIR} ${SAMPLESDIR}
	@for i in ${SAMPLES} ; do \
	${INSTALL_DATA} ${WRKSRC}/$$i ${SAMPLESDIR} ; \
	done

install-utils:
.if (${EMACS_PORT} == "xemacs21-mule")
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/bbdb-wl.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/im-wl.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
	@${INSTALL_DATA} ${WRKSRC}/utils/wl-user-agent.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl
.else
.if (${EMACS_PORT} == "emacs" || ${EMACS_PORT} == "mule")
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
.else
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif
	@${INSTALL_DATA} ${WRKSRC}/utils/bbdb-wl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
	@${INSTALL_DATA} ${WRKSRC}/utils/im-wl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
	@${INSTALL_DATA} ${WRKSRC}/utils/wl-user-agent.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
.endif

install-manifest:
	@${CAT} ${PKGDIR}/PLIST.${EMACS_PORT} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s!^%%EMACS_PACKAGESDIR%%!!" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} ${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/
	@${INSTALL_DATA} ${FILESDIR}/_pkg.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl/

.include <bsd.port.mk>
