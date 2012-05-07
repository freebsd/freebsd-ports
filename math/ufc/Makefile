# New ports collection makefile for:	ufc
# Date created:				27 March 2012
# Whom:					Jason Bacon <jwbacon@tds.net>
#
# $FreeBSD$
#

PORTNAME=	ufc
PORTVERSION=	2.0.5
CATEGORIES=	math python
MASTER_SITES=	http://launchpad.net/${PORTNAME}/2.0.x/${PORTVERSION}/+download/

MAINTAINER=	jwbacon@tds.net
COMMENT=	Unified framework for finite element assembly

BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20

# LICENSE=	public domain

USE_CMAKE=	yes
USE_PYTHON=	-2.7
PYDISTUTILS_PKGNAME=	ufc

FETCH_ARGS=	-F

post-patch:
	${REINPLACE_CMD} -e 's|lib/pkgconfig|libdata/pkgconfig|g' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.mk>
