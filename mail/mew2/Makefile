# New ports collection makefile for: Mew
# Date created:		21 November 1997
# Whom:			Kiriyama Kazuhiko <kiri@kiri.toba-cmt.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mew
PORTVERSION=	${MEW_VER}
CATEGORIES=	mail elisp
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/ \
		ftp://ftp.kyushu-u.ac.jp/pub/Misc/mew/release/ \
		${MASTER_SITE_PORTS_JP}
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER?=	kiri@FreeBSD.org
COMMENT?=	Message interface to Emacs Window (version 2) for emacs21

# Mew major version
MEW_MAJOR_VER?=	2

# distfile version
MEW_VER=	${MEW_MAJOR_VER}.2

# document install directory by install-doc target
MEW_DOCDIR?=	share/doc/${PORTNAME}${MEW_MAJOR_VER}

# emacs port setup
EMACS_PORT_NAME?=	emacs21

# target name for make build and install
ALL_TARGET?=	all info jinfo
INSTALL_TARGET?=	install install-info install-jinfo install-etc

# environments
MAKE_ENV+=	EMACS_LIBDIR=${EMACS_LIBDIR} MEW_MAJOR_VER=${MEW_MAJOR_VER}
PLIST_SUB+=	MEW_MAJOR_VER=${MEW_MAJOR_VER}

# manuals
MAN1=		mewcat.1 mewdecode.1 mewencode.1 mewls.1 incm.1

post-patch:
	for f in mew-key.el info/mew.texi; do \
		${PERL} -i -pe 's,%%MEW_MAJOR_VER%%,${MEW_MAJOR_VER},g' ${WRKSRC}/$${f}; \
	done

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${MEW_DOCDIR}
	(cd ${WRKSRC} ; \
		${INSTALL_DATA} 00* ${PREFIX}/${MEW_DOCDIR}/ ; \
		for dir in contrib; do \
			${CP} -R $${dir} ${PREFIX}/${MEW_DOCDIR}/ ; \
		done)
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${MEW_DOCDIR}
.endif

############################################################
## Make DESCR and PLIST (only for MAINTAINER use)
############################################################
#.if ${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule"
#ELISPDIR=	${PREFIX}/${EMACS_PACKAGESDIR}/lisp/${PORTNAME}${MEW_MAJOR_VER}
#INFODIR=	${PREFIX}/${EMACS_PACKAGESDIR}/info
#ETCDIR=		${PREFIX}/${EMACS_PACKAGESDIR}/etc/${PORTNAME}${MEW_MAJOR_VER}
#.else
#ELISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}${MEW_MAJOR_VER}
#INFODIR=	${PREFIX}/info
#ETCDIR=		${PREFIX}/${EMACS_LIBDIR}/etc/${PORTNAME}${MEW_MAJOR_VER}
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
#		MEW_MAJOR_VER=${MEW_MAJOR_VER} \
#		${SH} ${FILESDIR}/tmpl2file.sh
#	${SETENV} EMACS_PORT_NAME=${EMACS_PORT_NAME} WRKTMPDIR=${PKGDIR} \
#		${SH} ${FILESDIR}/message.sh
#	${CHOWN} kiri:staff ${PKGDIR}/pkg-comment ${PKGDIR}/pkg-descr ${PKGDIR}/pkg-message
#
#arrange:
#.if ${EMACS_PORT_NAME} == "xemacs21" || ${EMACS_PORT_NAME} == "xemacs21-mule"
#	${MAKE} PLIST_SUB_EXCLS="${PLIST_SUB_EXCLS}" \
#		DIRRM2RMDIRS="${ETCDIR:S,^${PREFIX}/,,:S,/${PORTNAME}${MEW_MAJOR_VER}$,,} \
#			${ELISPDIR:S,^${PREFIX}/,,:S,/${PORTNAME}${MEW_MAJOR_VER}$,,} \
#			${EMACS_PACKAGESDIR} ${EMACS_PACKAGESDIR}/lisp \
#			${EMACS_PACKAGESDIR}/info ${EMACS_PACKAGESDIR}/etc \
#			${EMACS_PACKAGESDIR}/man ${EMACS_PACKAGESDIR}/pkginfo" \
#		DIRRMDEPTH=2 plist
#.else
#	${MAKE} PLIST_SUB_EXCLS="${PLIST_SUB_EXCLS}" \
#		DIRRM2RMDIRS="${ETCDIR:S,^${PREFIX}/,,:S,/${PORTNAME}${MEW_MAJOR_VER}$,,} \
#			${ELISPDIR:S,^${PREFIX}/,,:S,/${PORTNAME}${MEW_MAJOR_VER}$,,} \
#			${EMACS_LIBDIR}/${EMACS_VER}/site-lisp \
#			${EMACS_LIBDIR}/${EMACS_VER}" \
#		INFOFILES="mew.info mew.jis.info" DIRRMDEPTH=2 plist
#.endif
#	${INSTALL} -c -m 644 -o kiri -g staff ${WRKPLIST} ${PLIST}
#	${PERL} -i -pe 's@((?!mew)...|^.{0,2})%%MEW_MAJOR_VER%%@$$1\x32@g' ${PLIST}

.include <bsd.port.mk>
