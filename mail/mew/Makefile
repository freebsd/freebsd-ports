# New ports collection makefile for: Mew
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mew
PORTVERSION=	${MEW_VER}
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/old/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Misc/mew/old/ \
		${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Message interface to Emacs Window for emacs

# distfile version
MEW_VER=	1.94.2

.if !defined(EMACS_PORT_NAME)
# setup.el filename
EMACS_SETUPEL=	${PORTNAME}-setup.el
.endif

# document install directory by install-doc target
MEW_DOCDIR?=	share/doc/${PORTNAME}

# emacs port setup
EMACS_PORT_NAME?=	emacs19

# target name for make build and install
ALL_TARGET?=	all # info
INSTALL_TARGET?=install install-info install-etc

# depends
RUN_DEPENDS=	imali:${PORTSDIR}/mail/im

# environments
MAKE_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR}
SCRIPTS_ENV+=	TARGETS="${EMACS_SETUPEL}" EMACS_SETUPEL=${EMACS_SETUPEL:S/.el$//}
PLIST_SUB+=	MEW_DOCDIR=${MEW_DOCDIR} EMACS_SETUPEL=${EMACS_SETUPEL}

pre-configure:
.if defined(EMACS_SETUPEL)
	@${CP} ${FILESDIR}/${EMACS_SETUPEL}.in ${WRKDIR}
.endif

post-install:
.if defined(EMACS_SETUPEL)
	${INSTALL_DATA} ${WRKDIR}/${EMACS_SETUPEL} \
			${PREFIX}/${EMACS_LIBDIR}/site-lisp
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${MEW_DOCDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* ${PREFIX}/${MEW_DOCDIR}/ ; \
		for dir in contrib patches; do \
			${CP} -R $${dir} ${PREFIX}/${MEW_DOCDIR}/ ; \
		done)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${MEW_DOCDIR}
.endif

############################################################
## Make DESCR and PLIST (only for MAINTAINER use)
############################################################
#.if ${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule"
#ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/${PORTNAME}
#INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
#ETCDIR=		${PREFIX}/${EMACS_PACKAGESDIR}/etc/${PORTNAME}
#.else
#ELISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
#INFODIR=	${PREFIX}/info
#ETCDIR=		${PREFIX}/${EMACS_LIBDIR}/etc/${PORTNAME}
#REQUIRE=	(require \'${EMACS_SETUPEL:S/^mew-/&${EMACS_PORT_NAME}-/:S/.el$//})
#.endif
#SCRIPTS_ENV+=	EMACS_PORTSDIR=${EMACS_PORTSDIR:S,^${PORTSDIR}/,,} \
#		PKGNAME=${PKGNAME} ELISPDIR=${ELISPDIR} INFODIR=${INFODIR} \
#		ETCDIR=${ETCDIR} EMACS_CMD=${EMACS_CMD:S,${PREFIX}/bin/,,} \
#		PORTNAME=${PORTNAME} EMACS_PORT_NAME=${EMACS_PORT_NAME}
#
#pre-plist:
#	mkdir -p ${ELISPDIR} ${INFODIR} ${ETCDIR} \
#		${PREFIX}/${EMACS_LIBDIR_WITH_VER}/site-lisp
#
#pre-arrange:
#	${SETENV} ${SCRIPTS_ENV} WRKTMPDIR=${PKGDIR} TMPL_FILES=pkg-descr \
#		${SH} ${FILESDIR}/tmpl2file.sh
#	${SETENV} ${SCRIPTS_ENV} WRKTMPDIR=${PKGDIR} ${SH} ${FILESDIR}/message.sh
#	${CHOWN} kiri:staff ${PKGDIR}/pkg-comment ${PKGDIR}/pkg-descr ${PKGDIR}/pkg-message
#
#arrange:
#.if ${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule"
#	${MAKE} PLIST_SUB_EXCLS="${PLIST_SUB_EXCLS}" \
#		DIRRM2RMDIRS="${ETCDIR:S,^${PREFIX}/,,:S,/${PORTNAME}$,,} \
#			${ELISPDIR:S,^${PREFIX}/,,:S,/${PORTNAME}$,,} \
#			${EMACS_PACKAGESDIR} ${EMACS_PACKAGESDIR}/lisp \
#			${EMACS_PACKAGESDIR}/info ${EMACS_PACKAGESDIR}/etc \
#			${EMACS_PACKAGESDIR}/man ${EMACS_PACKAGESDIR}/pkginfo" \
#		DIRRMDEPTH=2 plist
#.else
#	${MAKE} PLIST_SUB_EXCLS="${PLIST_SUB_EXCLS}" \
#		DIRRM2RMDIRS="${ETCDIR:S,^${PREFIX}/,,:S,/${PORTNAME}$,,} \
#			${ELISPDIR:S,^${PREFIX}/,,:S,/${PORTNAME}$,,} \
#			${EMACS_LIBDIR}/${EMACS_VER}/site-lisp \
#			${EMACS_LIBDIR}/${EMACS_VER}" \
#		INFOFILES="mew.info mew.jis.info" DIRRMDEPTH=2 plist
#.endif
#	${INSTALL} -c -m 644 -o kiri -g staff ${WRKPLIST} ${PLIST}

.include <bsd.port.mk>
