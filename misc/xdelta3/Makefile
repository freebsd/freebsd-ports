# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	xdelta
PORTVERSION=	3.0.11
DISTVERSIONPREFIX=	v
PORTEPOCH=	1
CATEGORIES?=	misc devel
PKGNAMESUFFIX=	3

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

LICENSE=	GPLv2+

USES=		autoreconf gmake

USE_GITHUB=	yes
GH_ACCOUNT=	jmacd
GH_PROJECT=	xdelta-devel

WRKSRC_SUBDIR=	xdelta3

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xdelta3 man/man1/xdelta3.1.gz

post-patch:
	@${REINPLACE_CMD} -e \
		'/_POSIX_/d ; \
		 /_C99_/d' ${WRKSRC}/xdelta3.h

.include <bsd.port.mk>
