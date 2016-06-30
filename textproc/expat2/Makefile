# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.1.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

GNU_CONFIGURE=	yes
ALL_TARGET=	default
USES=		dos2unix libtool pathfix tar:bz2
DOS2UNIX_GLOB=	*.txt
USE_LDCONFIG=	yes

post-stage:
	${LN} -s libexpat.so.1 ${STAGEDIR}${PREFIX}/lib/libexpat.so.6

.include <bsd.port.mk>
