# Created by: Chris Calvey <chris@securityforensics.co.uk>
# $FreeBSD$

PORTNAME=	afflib
PORTVERSION=	3.7.10
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

USE_LDCONFIG=	yes
USES=		autoreconf fuse libtool pathfix readline ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-s3=yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
