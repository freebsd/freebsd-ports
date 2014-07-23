# Created by: pauls
# $FreeBSD$

PORTNAME=	spybye
PORTVERSION=	0.3
PORTREVISION=	3
CATEGORIES=	security www
MASTER_SITES=	http://www.monkey.org/~provos/

MAINTAINER=	pauls@utdallas.edu
COMMENT=	Web proxy to detect malware

LIB_DEPENDS=	libevent-1.4.so:${PORTSDIR}/devel/libevent

OPTIONS_DEFINE=	CLAMAV
CLAMAV_DESC=	Enable CLAMAV support

USE_RC_SUBR=	spybye
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCLAMAV}
LIB_DEPENDS+=	libclamav.so:${PORTSDIR}/security/clamav
CONFIGURE_ARGS+=	--with-libclamav=${PREFIX}/bin
.endif

.include <bsd.port.post.mk>
