PORTNAME=	cld3
PORTVERSION=	3.5.0
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Compact Language Detection for Ruby
WWW=		https://github.com/akihikodaki/cld3-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libprotobuf.so:devel/protobuf
RUN_DEPENDS=	rubygem-ffi>=1.1.0<1.16.0:devel/rubygem-ffi

USES=		gem pkgconfig

.include <bsd.port.mk>
