# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	xdelta
PORTVERSION=	3.0.6
PORTEPOCH=	1
CATEGORIES?=	misc devel
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}3-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source binary diff, VCDIFF/RFC 3284 delta compression

LICENSE=	GPLv2 # (or later)

LATEST_LINK=	xdelta3

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		xdelta3.1
PLIST_FILES=	bin/xdelta3

post-patch:
	@${REINPLACE_CMD} -e \
		'/_POSIX_/d ; \
		 /_C99_/d' ${WRKSRC}/xdelta3.h

.include <bsd.port.mk>
