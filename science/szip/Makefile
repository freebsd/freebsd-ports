# Created by: glewis
# $FreeBSD$

PORTNAME=	szip
PORTVERSION=	2.1.1
CATEGORIES=	science archivers
MASTER_SITES=	https://support.hdfgroup.org/ftp/lib-external/szip/${PORTVERSION}/src/ \
		https://support.hdfgroup.org/ftp/lib-external/szip/previous/${PORTVERSION}/src/ \
		LOCAL/sunpoet
PKGNAMEPREFIX=	hdf-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lossless compression library for scientific data

LICENSE=	SZIP
LICENSE_NAME=	SZIP License
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror no-dist-sell pkg-mirror no-pkg-sell auto-accept

CONFLICTS_INSTALL=	libaec

USES=		libtool

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
LIBS+=		-lm
TEST_TARGET=	check
USE_LDCONFIG=	yes

.include <bsd.port.mk>
