# New ports collection makefile for:	scim-kmfl-khmer
# Date created:		30 July 2010
# Whom:			Kuan-Chung Chiu <buganini@gmail.com>
#
# $FreeBSD$

PORTNAME=	scim
PORTVERSION=	1.0
CATEGORIES=	textproc
MASTER_SITES=	http://download.github.com/ \
		http://security-hole.info/distfile/
PKGNAMESUFFIX=	-kmfl-khmer
DISTNAME=	buganini-kmfl-khmer-1.0-0-ga20cc89

MAINTAINER=	buganini@gmail.com
COMMENT=	KMFL SCIM IMEngine keyboard for Khmer language

RUN_DEPENDS=	kmflcomp:${PORTSDIR}/textproc/kmflcomp \
 		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/kmfl.so:${PORTSDIR}/textproc/scim-kmfl-imengine

WRKSRC=		${WRKDIR}/buganini-kmfl-khmer-a20cc89/kmfl/
NO_BUILD=	yes

PLIST_FILES=	${DATADIR_REL}/kmfl/khmer.kmn \
		${DATADIR_REL}/kmfl/icons/khmer.bmp
PLIST_DIRS=	${DATADIR_REL}/kmfl/icons \
		${DATADIR_REL}/kmfl \
		${DATADIR_REL}

do-install:
	${MKDIR} ${DATADIR}/kmfl/icons
	${INSTALL_DATA} ${WRKSRC}/*.kmn ${DATADIR}/kmfl
	${INSTALL_DATA} ${WRKSRC}/*.bmp ${DATADIR}/kmfl/icons

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
