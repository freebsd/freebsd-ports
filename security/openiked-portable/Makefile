PORTNAME=	openiked
DISTVERSION=	7.2
CATEGORIES=	security net
MASTER_SITES=	OPENBSD/OpenIKED
PKGNAMESUFFIX=	-portable

MAINTAINER=	david@lapinbilly.eu
COMMENT=	IKEv2 daemon
WWW=		https://github.com/openiked/openiked-portable

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:devel/libevent

USES=		cmake ssl
USE_RC_SUBR=	iked

CONFLICTS_INSTALL=	openiked

USERS=		_iked
GROUPS=		_iked

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/iked.conf \
	    ${STAGEDIR}${PREFIX}/etc/iked.conf.sample

.include <bsd.port.mk>
