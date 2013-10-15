# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	xdelta
PORTVERSION=	3.0.7
PORTEPOCH=	1
CATEGORIES?=	misc devel
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	3
DISTNAME=	${PORTNAME}3-${PORTVERSION}

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

LICENSE=	GPLv2 # (or later)

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xdelta3 man/man1/xdelta3.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/_POSIX_/d ; \
		 /_C99_/d' ${WRKSRC}/xdelta3.h

.include <bsd.port.mk>
