PORTNAME=	afflib
PORTVERSION=	3.7.16
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced Forensics Format library and utilities

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

USE_GITHUB=	yes
GH_ACCOUNT=	sshock
GH_PROJECT=	AFFLIBv3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-s3=yes
USES=		autoreconf cpe fuse libtool pathfix readline ssl
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
