PORTNAME=	openiked
PORTVERSION=	7.0
CATEGORIES=	security net
MASTER_SITES=	OPENBSD/OpenIKED
PKGNAMESUFFIX=	-portable

MAINTAINER=	david@lapinbilly.eu
COMMENT=	IKEv2 daemon

LICENSE=	ISCL

LIB_DEPENDS=	libevent.so:devel/libevent

CONFLICTS_INSTALL=	openiked
USES=			cmake ssl

USE_RC_SUBR=	iked
USERS=		_iked
GROUPS=		_iked

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/iked.conf \
	    ${STAGEDIR}${PREFIX}/etc/iked.conf.sample

.include <bsd.port.mk>
