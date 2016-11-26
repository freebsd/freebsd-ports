# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

PORTNAME=	expat
PORTVERSION=	2.2.0
CATEGORIES=	textproc
MASTER_SITES=	SF

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	XML 1.0 parser written in C

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
ALL_TARGET=	default
USES=		libtool pathfix tar:bz2
USE_LDCONFIG=	yes

post-stage:
	${LN} -s libexpat.so.1 ${STAGEDIR}${PREFIX}/lib/libexpat.so.6

.include <bsd.port.mk>
