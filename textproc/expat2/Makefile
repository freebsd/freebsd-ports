# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.1.1
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

GNU_CONFIGURE=	yes
ALL_TARGET=	default
USES=		libtool pathfix tar:bz2
USE_LDCONFIG=	yes

post-stage:
	${LN} -s libexpat.so.1 ${STAGEDIR}${PREFIX}/lib/libexpat.so.6

.include <bsd.port.mk>
