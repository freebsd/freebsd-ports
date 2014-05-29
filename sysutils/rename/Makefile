# Created by: Chad Castleberry AKA ritalin
# $FreeBSD$

PORTNAME=	rename
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://mirror2.unixfreunde.de/ \
		http://freebsd.unixfreunde.de/sources/

MAINTAINER=	jsa@FreeBSD.org
COMMENT=	Rename multiple files using regular expressions

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	bin/${PORTNAME}
MAN1=		rename.1

NO_STAGE=	yes
post-extract:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
