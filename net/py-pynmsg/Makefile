# $FreeBSD$

PORTNAME=	pynmsg
PORTVERSION=	0.3.1
CATEGORIES=	net python
MASTER_SITES=	FARSIGHT LOCAL/truckman/farsight

MAINTAINER=	truckman@FreeBSD.org
COMMENT=	Python wrapper for net/nmsg

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libnmsg.so:${PORTSDIR}/net/nmsg

USE_PYTHON=	distutils autoplist

CPPFLAGS+=	-I${LOCALBASE}/include

USES=		python

post-install:
	${STRIP_CMD} ${STAGEDIR}/${PREFIX}/lib/python2.7/site-packages/_nmsg.so

.include <bsd.port.mk>
