# $FreeBSD$

PORTNAME=	binwalk
PORTVERSION=	2.0.1
CATEGORIES=	security python
MASTER_SITES=	http://github.com/devttys0/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Search binary images for embedded files and executable code

LICENSE=	MIT

USES=		python gmake
USE_PYTHON=	autoplist distutils
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BUILD_DEPENDS=	liblzma>=0:${PORTSDIR}/archivers/py-liblzma
RUN_DEPENDS=	/usr/local/bin/7z:${PORTSDIR}/archivers/p7zip \
		/usr/local/bin/cabextract:${PORTSDIR}/archivers/cabextract

.include <bsd.port.mk>
