# New ports collection makefile for:	Wanderlust (for emacs)
# Version required:	1.0.x
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

DISTNAME=	wl-1.0.3
PKGNAME=	wanderlust-${EMACS_PORT}-1.0.3
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/wanderlust/stable/ \
		ftp://daidai.kuis.kyoto-u.ac.jp/pub/mirror/ftp.gohome.org/pub/elisp/wl/stable/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/

MAINTAINER=	nobutaka@nobutaka.com

.if !defined (IS_SLAVE)
# for emacs19
EMACS_NAME=	emacs
EMACS_PORT=	emacs
EMACS_VER=	19.34
EMACS_LIBDIR=	share/emacs
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
.if defined(EMACS_PACKAGESDIR)
BUILD_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/semi/mime-setup.el:${PORTSDIR}/editors/semi-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/semi/mime-setup.el:${PORTSDIR}/editors/semi-${EMACS_PORT}
.else
BUILD_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/semi/mime-setup.el:${PORTSDIR}/editors/semi-${EMACS_PORT}
RUN_DEPENDS+=	${PREFIX}/${EMACS_LIBDIR}/site-lisp/semi/mime-setup.el:${PORTSDIR}/editors/semi-${EMACS_PORT}
.endif

.if (${EMACS_PORT} == "xemacs-mule")
DIRSECTION=	"Local Packages:"
ALL_TARGET=	all info
.endif
.if (${EMACS_PORT} == "emacs20" || ${EMACS_PORT} == "mule")
DIRSECTION=	"The Emacs editor and associated tools"
ALL_TARGET=	all info
.endif

PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} EMACS_VER_LIBDIR=${EMACS_VER_LIBDIR}

DOCSDIR=	${PREFIX}/share/doc/wanderlust
DOCS=		00README 00README.ja ChangeLog ChangeLog.ja
SAMPLESDIR=	${PREFIX}/share/examples/wanderlust
SAMPLES=	sample.addresses sample.dot.wl sample.folders

PLIST=		${PKGDIR}/PLIST.${EMACS_PORT}
MAKE_ARGS=	EMACS=${EMACS_CMD} ELISPDIR=${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust FLAGS="-batch -q -no-site-file -l ${WRKDIR}/wanderlust-startup.el"

post-configure:
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACS_LIBDIR%%,${EMACS_LIBDIR},g" \
		-e "s,%%EMACS_VER_LIBDIR%%,${EMACS_VER_LIBDIR},g" \
		< ${FILESDIR}/wanderlust-startup.${EMACS_PORT}.el.tmpl > ${WRKDIR}/wanderlust-startup.el

pre-install:
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust

post-install:
.if (${EMACS_PORT} == "xemacs-mule")
	@if [ ! -f ${PREFIX}/${EMACS_LIBDIR}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/${EMACS_VER_LIBDIR}/info/dir; \
	fi
	@${INSTALL_DATA} ${WRKSRC}/doc/wl-ja.info ${PREFIX}/${EMACS_VER_LIBDIR}/info
	@install-info --section=${DIRSECTION} ${PREFIX}/${EMACS_VER_LIBDIR}/info/wl-ja.info ${PREFIX}/${EMACS_VER_LIBDIR}/info/dir
.endif
.if (${EMACS_PORT} == "emacs20" || ${EMACS_PORT} == "mule")
	@${INSTALL_DATA} ${WRKSRC}/doc/wl-ja.info ${PREFIX}/info
	@install-info --section=${DIRSECTION} ${PREFIX}/info/wl-ja.info ${PREFIX}/info/dir
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for i in ${DOCS} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${DOCSDIR} ; \
	done
	@${INSTALL_DATA} ${WRKSRC}/doc/wl-ja.texi ${DOCSDIR}
.endif
.if (${EMACS_NAME} == "xemacs")
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/etc/wanderlust
	@for i in *.xpm ; do \
		${INSTALL_DATA} ${WRKSRC}/etc/$$i ${PREFIX}/${EMACS_LIBDIR}/etc/wanderlust ; \
	done
.endif
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp
	@${INSTALL_DATA} ${WRKSRC}/utils/bbdb-wl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
	@${INSTALL_DATA} ${WRKSRC}/utils/im-wl.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
	@${INSTALL_DATA} ${WRKSRC}/utils/wl-user-agent.el ${PREFIX}/${EMACS_LIBDIR}/site-lisp/wanderlust
	@${MKDIR} ${SAMPLESDIR}
	@for i in ${SAMPLES} ; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${SAMPLESDIR} ; \
	done
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
