PORTNAME=	Authen-SASL-Cyrus
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	XS SASL Authentication
WWW=		https://metacpan.org/release/Authen-SASL-Cyrus

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Authen-SASL>=0:security/p5-Authen-SASL
LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	INC="-I${LOCALBASE}/include"

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.mk>
