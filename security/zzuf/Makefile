# New ports collection makefile for:	zzuf
# Date created:		2007-03-03
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zzuf
PORTVERSION=	0.13
CATEGORIES=	security
MASTER_SITES=	http://caca.zoy.org/raw-attachment/wiki/zzuf/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Transparent application input fuzzer

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=	zzuf.1 zzcat.1
MAN3=	libzzuf.3

post-install:
	@${RM} -f ${PREFIX}/lib/zzuf/libzzuf.la

.include <bsd.port.mk>
