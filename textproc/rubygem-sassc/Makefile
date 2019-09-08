# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sassc
PORTVERSION=	2.1.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use libsass with Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libsass.so:textproc/libsass
RUN_DEPENDS=	rubygem-ffi>=1.9<2:devel/rubygem-ffi

USES=		gem gmake
USE_RUBY=	yes

post-patch:
	@${REINPLACE_CMD} -e '/ffi_lib/ s|__dir__|"${LOCALBASE}/lib"|' ${WRKSRC}/lib/sassc/native.rb

.include <bsd.port.mk>
