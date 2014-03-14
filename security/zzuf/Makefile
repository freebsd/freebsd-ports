# Created by: Peter Johnson <johnson.peter@gmail.com>
# $FreeBSD$

PORTNAME=	zzuf
PORTVERSION=	0.13
CATEGORIES=	security
MASTER_SITES=	http://caca.zoy.org/raw-attachment/wiki/zzuf/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Transparent application input fuzzer

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-install:
	@${RM} -f ${PREFIX}/lib/zzuf/libzzuf.la

.include <bsd.port.mk>
