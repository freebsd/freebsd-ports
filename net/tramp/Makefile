# New ports collection makefile for:	tramp (for emacs21)
# Date Created:		12 Dec 2001
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tramp
PORTVERSION=	2.0.28
CATEGORIES=	net elisp
MASTER_SITES=	http://savannah.nongnu.org/download/tramp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yoichi@FreeBSD.org

EMACS_PORT_NAME?=	emacs21

BUILD_WRKSRC=	${WRKSRC}/lisp
USE_GMAKE=	yes

TRAMP_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
DIRSECTION=	"The Emacs editor and associated tools"
INFOENTRY=	"* TRAMP: (tramp).                Transparent Remote Access, Multiple Protocol."
INFOENTRY_JA=	"* TRAMP-J: (tramp_ja).           Transparent Remote Access, Multiple Protocol."
PLIST_SUB+=	TRAMP_LISPDIR=${TRAMP_LISPDIR} \
		DIRSECTION=${DIRSECTION} \
		INFOENTRY=${INFOENTRY} INFOENTRY_JA=${INFOENTRY_JA}

.if !defined(NOPORTDOCS) && defined(JAPANESE_INFO)
BUILD_DEPENDS+=	jmakeinfo:${PORTSDIR}/japanese/texinfo
PLIST_SUB+=	JAPANESE_INFO=""
.else
PLIST_SUB+=	JAPANESE_INFO="@comment "
.endif

.if ${EMACS_PORT_NAME} == emacs20
PLIST_SUB+=	EMACS20_ONLY=""
.else
PLIST_SUB+=	EMACS20_ONLY="@comment "
.endif

pre-build:
.if ${EMACS_PORT_NAME} == emacs20
.for i in format-spec md5
	(cd ${WRKSRC}/contrib; ${EMACS_CMD} -batch -f batch-byte-compile ${i}.el)
	(${CP} -p ${WRKSRC}/contrib/${i}.el ${WRKSRC}/contrib/${i}.elc ${BUILD_WRKSRC})
.endfor
.endif
post-build:
.if !defined(NOPORTDOCS)
#	(cd ${WRKSRC}/texi; ${GMAKE} EMACS=${EMACS_CMD} MAKEINFO=makeinfo tramp.info)
.if defined(JAPANESE_INFO)
	(cd ${WRKSRC}/texi; ${GMAKE} EMACS=${EMACS_CMD} MAKEINFO=jmakeinfo tramp_ja.info)
.endif
.endif

do-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.el ${BUILD_WRKSRC}/*.elc ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/tramp2/*.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/info/tramp ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} ${PREFIX}/info/tramp ${PREFIX}/info/dir
.if defined(JAPANESE_INFO)
	${INSTALL_DATA} ${WRKSRC}/texi/tramp_ja.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY_JA} ${PREFIX}/info/tramp_ja.info ${PREFIX}/info/dir
.endif
.endif

.include <bsd.port.mk>
