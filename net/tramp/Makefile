# New ports collection makefile for:	tramp (for emacs21)
# Date Created:		12 Dec 2001
# Whom:			Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tramp
PORTVERSION=	0.0.20020121
CATEGORIES=	net elisp
MASTER_SITES=	http://tramp.sourceforge.net/download/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}

MAINTAINER=	yoichi@FreeBSD.org

EMACS_PORT_NAME?=	emacs21

BUILD_WRKSRC=	${WRKSRC}/lisp

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
	(cd ${WRKSRC}/contrib; ${MAKE} EMACS=${EMACS_CMD} format-spec.elc)
	(${CP} ${WRKSRC}/contrib/format-spec.el ${WRKSRC}/contrib/format-spec.elc ${BUILD_WRKSRC})
.endif
post-build:
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/texi; ${MAKE} EMACS=${EMACS_CMD} MAKEINFO=makeinfo tramp.info)
.if defined(JAPANESE_INFO)
	(cd ${WRKSRC}/texi; ${MAKE} EMACS=${EMACS_CMD} MAKEINFO=jmakeinfo tramp_ja.info)
.endif
.endif

do-install:
	${MKDIR} ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${BUILD_WRKSRC}/*.el ${BUILD_WRKSRC}/*.elc ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/tramp2/*.el ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/texi/tramp.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY} ${PREFIX}/info/tramp.info ${PREFIX}/info/dir
.if defined(JAPANESE_INFO)
	${INSTALL_DATA} ${WRKSRC}/texi/tramp_ja.info ${PREFIX}/info
	install-info --section=${DIRSECTION} --entry=${INFOENTRY_JA} ${PREFIX}/info/tramp_ja.info ${PREFIX}/info/dir
.endif
.endif

.include <bsd.port.mk>
