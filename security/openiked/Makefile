# $FreeBSD$

PORTNAME=	openiked
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	security net

MAINTAINER=	marcel@FreeBSD.org
COMMENT=	IKEv2 daemon

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		autoreconf libtool ssl

USE_GITHUB=	yes
GH_ACCOUNT=	xcllnt

USE_RC_SUBR=	iked
USERS=		_iked
GROUPS=		_iked

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--with-libevent-dir=${PREFIX} --with-mantype=man

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/ikeca.cnf \
	    ${STAGEDIR}${PREFIX}/etc/ikeca.cnf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/iked.conf \
	    ${STAGEDIR}${PREFIX}/etc/iked.conf.sample

.include <bsd.port.mk>
