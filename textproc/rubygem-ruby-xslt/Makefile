PORTNAME=	ruby-xslt
PORTVERSION=	0.9.10
PORTREVISION=	3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	XSLT processor in pure Ruby
WWW=		https://github.com/glejeune/ruby-xslt

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gem gnome
USE_GNOME=	libxslt

CONFIGURE_ARGS=	--with-cflags=-Wno-incompatible-function-pointer-types

.include <bsd.port.mk>
