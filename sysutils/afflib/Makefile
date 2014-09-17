# Created by: Chris Calvey <chris@securityforensics.co.uk>
# $FreeBSD$

PORTNAME=	afflib
PORTVERSION=	3.7.4
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.digitalcorpora.org/downloads/${PORTNAME}/

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Advanced Forensics Format library and utilities

LICENSE=	BSD4CLAUSE

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libcurl.so:${PORTSDIR}/ftp/curl

USE_LDCONFIG=	yes
USE_OPENSSL=	yes
USES=		fuse libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-s3=yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
