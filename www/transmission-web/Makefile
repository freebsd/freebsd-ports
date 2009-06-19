# New ports collection makefile for:	transmission-web
# Date created:				14 July 2008
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	www net-p2p
PKGNAMESUFFIX=	-web

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A fast and lightweight WebUI for Transmission BitTorrent client

DESCR=		${.CURDIR}/pkg-descr
MASTERDIR=	${.CURDIR}/../../net-p2p/transmission-cli
PLIST=		${.CURDIR}/pkg-plist
SLAVEPORT=	web

NO_BUILD=	yes

post-extract:
	@${FIND} ${WRKSRC}/web -name .svn | ${XARGS} ${RM} -rf

do-install:
	@${MKDIR} ${DATADIR}/web
	@(cd ${WRKSRC}/web && ${COPYTREE_SHARE} \* ${DATADIR}/web)

.include "${MASTERDIR}/Makefile"
