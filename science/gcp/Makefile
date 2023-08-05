PORTNAME=	gcp
DISTVERSIONPREFIX=	v
DISTVERSION=	2.3.1
CATEGORIES=	science # chemistry

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Geometrical Counter-Poise Correction
WWW=		https://github.com/grimme-lab/gcp

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		fortran meson
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	grimme-lab
GH_TUPLE=	grimme-lab:mctc-lib:v0.2.0:mctc_lib/subprojects/mctc-lib \
		grimme-lab:mstore:v0.1.1:mstore/subprojects/mstore

PLIST_FILES=	bin/mctc-gcp \
		lib/libmctc-gcp.a \
		lib/libmctc-gcp.so \
		lib/libmctc-gcp.so.${DISTVERSION:R:R} \
		lib/libmctc-gcp.so.${DISTVERSION} \
		libdata/pkgconfig/mctc-gcp.pc

.include <bsd.port.mk>
