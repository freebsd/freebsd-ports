PORTNAME=	afflib
PORTVERSION=	3.7.20
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced Forensics Format library and utilities
WWW=		https://github.com/sshock/AFFLIBv3

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	sshock
GH_PROJECT=	AFFLIBv3

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--enable-s3=yes
USES=		autoreconf cpe fuse libtool pathfix readline ssl
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
