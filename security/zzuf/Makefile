# New ports collection makefile for:	zzuf
# Date created:		2007-03-03
# Whom:			Peter Johnson <johnson.peter@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	zzuf
PORTVERSION=	0.9
CATEGORIES=	security
MASTER_SITES=	http://sam.zoy.org/zzuf/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	Transparent application input fuzzer

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

MAN1=	zzuf.1

post-install:
	@${RM} -f ${PREFIX}/lib/zzuf/libzzuf.la

.include <bsd.port.mk>
