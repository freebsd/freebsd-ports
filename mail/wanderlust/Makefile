# New ports collection makefile for:	Wanderlust (for emacs)
# Date created:		7 Apr 1999
# Whom: 		MANTANI Nobutaka <nobutaka@nobutaka.com>
#
# $FreeBSD$
#

PORTNAME=	wanderlust
PORTVERSION=	1.1.1
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.gohome.org/wl/stable/ \
		ftp://ftp.ring.gr.jp/pub/text/elisp/wl/stable/ \
		ftp://ftp.jaist.ac.jp/pub/GNU/elisp/ftp.gohome.org/wl/stable/ \
		ftp://daidai.kuis.kyoto-u.ac.jp/pub/mirror/ftp.gohome.org/pub/elisp/wl/stable/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	wl-${PORTVERSION}

MAINTAINER=	nobutaka@nobutaka.com

MIMEUI_PRODUCT?=	semi
MIMEUI_VERSION?=	1.13.7
MIMEUI_PORT_NAME?=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-current
MIMEUI_COOKIE=	${MIMEUI_PRODUCT}-${EMACS_PORT_NAME}-${MIMEUI_VERSION}.FreeBSD-packages

.if !defined (IS_SLAVE)
# for emacs19
EMACS_PORT_NAME=	emacs
.endif

.if (${EMACS_PORT_NAME} == "emacs20" || ${EMACS_PORT_NAME} == "mule" || \
     ${EMACS_PORT_NAME} == "xemacs21-mule")
WITH_MULE=yes
.else
WITHOUT_MULE=yes
.endif

# depends on semi
BUILD_DEPENDS+=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}
RUN_DEPENDS+=	${LOCALBASE}/share/semi/${MIMEUI_COOKIE}:${PORTSDIR}/editors/${MIMEUI_PORT_NAME}

.if defined(EMACS_PACKAGESDIR)
ALL_TARGET=	package
INSTALL_TARGET=	install-package
UTILSDIR=	${EMACS_PACKAGESDIR}/lisp/wl
STARTUPDIR=	${EMACS_PACKAGESDIR}/lisp/wl
.else
ALL_TARGET=	all info
INSTALL_TARGET= install install-info
INFODIR=	${PREFIX}/info
UTILSDIR=	${EMACS_SITE_LISPDIR}/wl
.if (${EMACS_PORT_NAME} == "xemacs20")
STARTUPDIR=	${EMACS_SITE_LISPDIR}
.else
STARTUPDIR=	${EMACS_VERSION_SITE_LISPDIR}
.endif
.endif

DIRSECTION=	"The Emacs editor and associated tools"
PORTDOCDIR=	share/doc/wanderlust
DOCS=		README README.ja ChangeLog BUGS BUGS.ja \
		NEWS NEWS.ja doc/wl-ja.texi doc/wl.texi
SAMPLESDIR=	share/examples/wanderlust
SAMPLESLANG=	en ja
SAMPLES=	dot.addresses dot.folders dot.wl
UTILS=		bbdb-wl.el im-wl.el ssl.el

PLIST_SUB=	EMACS_LIBDIR=${EMACS_LIBDIR} \
		EMACS_LIBDIR_WITH_VER=${EMACS_LIBDIR_WITH_VER} \
		EMACS_PACKAGESDIR=${EMACS_PACKAGESDIR} \
		DIRSECTION=${DIRSECTION}

PLIST=		${PKGDIR}/PLIST.${EMACS_PORT_NAME}
MAKE_ARGS+=	EMACS=${EMACS_CMD} XEMACS=${EMACS_CMD} \
		LISPDIR=${PREFIX}/${EMACS_SITE_LISPDIR} \
		FLAGS="-batch -q -no-site-file -l ${WRKDIR}/wanderlust-startup.el"
.if defined(EMACS_PACKAGESDIR)
MAKE_ARGS+=	PACKAGEDIR=${PREFIX}/${EMACS_PACKAGESDIR}
.else
MAKE_ARGS+=	INFODIR=${INFODIR}
.endif

post-extract:
	@${CP} ${FILESDIR}/WL-CFG ${WRKSRC}
.if defined(WITH_MULE) && !defined(WITHOUT_MULE)
	@${ECHO} '(setq wl-info-lang (list "en" "ja"))' >> ${WRKSRC}/WL-CFG
.else
	@${ECHO} '(setq wl-info-lang "en")' >> ${WRKSRC}/WL-CFG
.endif

post-configure:
	@${SED} \
		-e "s,%%PREFIX%%,${PREFIX},g" \
		-e "s,%%EMACS_LIBDIR%%,${EMACS_LIBDIR},g" \
		-e "s,%%EMACS_LIBDIR_WITH_VER%%,${EMACS_LIBDIR_WITH_VER},g" \
		-e "s,%%EMACS_PACKAGESDIR%%,${EMACS_PACKAGESDIR},g" \
		< ${FILESDIR}/wanderlust-startup.${EMACS_PORT_NAME}.el.tmpl > ${WRKDIR}/wanderlust-startup.el

pre-build:
.if defined(EMACS_PACKAGESDIR)
	@${CP} ${FILESDIR}/_pkg.el ${WRKSRC}
.endif

post-install:
.if !defined(EMACS_PACKAGESDIR)
	@${MAKE} install-info
.endif
.if !defined(NOPORTDOCS)
	@${MAKE} install-docs
.endif
.if (${EMACS_PORT_NAME} == "xemacs20")
	@${MAKE} install-icons
.endif
	@${MAKE} install-samples
	@${MAKE} install-utils
.if defined(EMACS_PACKAGESDIR)
	@${MAKE} install-manifest
.endif
	@${CAT} ${PKGMESSAGE}

# local targets
install-info:
	@install-info --section=${DIRSECTION} ${WRKSRC}/doc/wl.info ${INFODIR}/dir
.if defined(WITH_MULE) && !defined(WITHOUT_MULE)
	@install-info --section=${DIRSECTION} ${WRKSRC}/doc/wl-ja.info ${INFODIR}/dir
.endif

install-docs:
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${PREFIX}/${PORTDOCDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/elmo/ChangeLog ${PREFIX}/${PORTDOCDIR}/ChangeLog.elmo
	${INSTALL_DATA} ${WRKSRC}/wl/ChangeLog ${PREFIX}/${PORTDOCDIR}/ChangeLog.wl

install-icons:
	@${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/etc/wl
	cd ${WRKSRC}/etc/icons ; \
	for i in *.xpm ; do \
		${INSTALL_DATA} $$i ${PREFIX}/${EMACS_LIBDIR}/etc/wl ; \
	done

install-samples:
.for l in ${SAMPLESLANG}
	${MKDIR} ${PREFIX}/${SAMPLESDIR}/$l
	for i in ${SAMPLES} ; do \
		${INSTALL_DATA} ${WRKSRC}/samples/$l/$$i ${PREFIX}/${SAMPLESDIR}/$l; \
	done
.endfor

install-utils:
	@${MKDIR} ${PREFIX}/${UTILSDIR}
.for i in ${UTILS}
	${INSTALL_DATA} ${WRKSRC}/utils/${i} ${PREFIX}/${UTILSDIR}
.endfor
.if (${EMACS_PORT_NAME} == "emacs")
	@${INSTALL_DATA} ${WRKSRC}/wl/wl-mule.el ${PREFIX}/${EMACS_SITE_LISPDIR}/wl
.endif
	@${MKDIR} ${PREFIX}/${STARTUPDIR}
	@${INSTALL_DATA} ${WRKDIR}/wanderlust-startup.el ${PREFIX}/${STARTUPDIR}

install-manifest:
	@${CAT} ${PKGDIR}/PLIST.${EMACS_PORT_NAME} | ${GREP} -e "^%%EMACS_PACKAGESDIR%%" | \
		${SED} -e "s!^%%EMACS_PACKAGESDIR%%!!" > ${WRKDIR}/${MANIFEST}
	@${INSTALL_DATA} ${WRKDIR}/${MANIFEST} ${PREFIX}/${EMACS_PACKAGESDIR}/pkginfo/
	@${INSTALL_DATA} ${FILESDIR}/_pkg.el ${PREFIX}/${EMACS_PACKAGESDIR}/lisp/wl

.include <bsd.port.mk>
