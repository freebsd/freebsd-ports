PORTNAME=	gsl
PORTVERSION=	2.1.0.2
PORTREVISION=	5
CATEGORIES=	math rubygems
MASTER_SITES=	RG
PKGNAMEPREFIX=	rubygem-rb-

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Ruby extension library for GSL (GNU Scientific Library)
WWW=		https://github.com/blackwinter/rb-gsl

LICENSE=	GPLv2

LIB_DEPENDS=	libgsl.so:math/gsl
RUN_DEPENDS=	rubygem-narray>=0.5.9:math/rubygem-narray

USES=		gem

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=int-conversion"
.endif

.include <bsd.port.mk>
