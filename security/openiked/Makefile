# $FreeBSD$

PORTNAME=	openiked
PORTVERSION=	1.2
CATEGORIES=	security net ipv6

MAINTAINER=	marcel@FreeBSD.org
COMMENT=	IKEv2 daemon

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:devel/libevent2

BROKEN_FreeBSD_9=does not build

USE_GITHUB=	yes
GH_ACCOUNT=	xcllnt

USE_RC_SUBR=	iked
USERS=		_iked
GROUPS=		_iked

USES=           autoreconf libtool ssl
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-libevent-dir=${PREFIX}

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/ikeca.cnf \
	    ${STAGEDIR}${PREFIX}/etc/ikeca.cnf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/iked.conf \
	    ${STAGEDIR}${PREFIX}/etc/iked.conf.sample

.include <bsd.port.mk>
