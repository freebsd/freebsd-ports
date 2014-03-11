# Created by: ijliao
# $FreeBSD$

PORTNAME=	fngrab
PORTVERSION=	0.0.4
CATEGORIES=	net-p2p python
MASTER_SITES=	SF/freebbs/${PORTNAME}-${PORTVERSION}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A replacement for the official Freenet Project's freenet_request

BUILD_DEPENDS=	${PYXML}
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	FreenetGrab

NO_STAGE=	yes
post-install:
	@${MV} ${PREFIX}/bin/fngrab.py ${PREFIX}/bin/fngrab

.include <bsd.port.mk>
