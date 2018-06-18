# Created by: Carlos J Puga Medina <cpm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grive2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1-dev
CATEGORIES=	net

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Open source client for Google Drive

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: JsonValTest.cc.o: undefined reference to boost::unit_test::ut_detail::normalize_test_case_name

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgcrypt.so:security/libgcrypt \
		libgpg-error.so:security/libgpg-error \
		libyajl.so:devel/yajl

USES=		cmake localbase pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	vitalif
GH_TAGNAME=	11a3d78

PLIST_FILES=	bin/grive \
		man/man1/grive.1.gz

.include <bsd.port.mk>
