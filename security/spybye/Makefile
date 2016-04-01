# Created by: pauls
# $FreeBSD$

PORTNAME=	spybye
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Web proxy to detect malware

LICENSE=	GPLv2

LIB_DEPENDS=	libevent.so:devel/libevent2

OPTIONS_DEFINE=	CLAMAV
CLAMAV_DESC=	Enable CLAMAV support

USE_RC_SUBR=	spybye
GNU_CONFIGURE=	yes

CLAMAV_LIB_DEPENDS=	libclamav.so:security/clamav
CLAMAV_CONFIGURE_ON=	--with-libclamav=${PREFIX}/bin

.include <bsd.port.mk>
