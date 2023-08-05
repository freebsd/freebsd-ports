PORTNAME=	easysoap
PORTVERSION=	0.8.0
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SWANSONG
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ SOAP library based on Expat
WWW=		http://easysoap.sourceforge.net/

LICENSE=	LGPL21

DEPRECATED=	Last release was in 2006
EXPIRATION_DATE=	2023-09-30

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool localbase ssl
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_stdcpp_main=no

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ( ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && ${SSL_DEFAULT} == base ) || ${SSL_DEFAULT:Mopenssl3*}
BROKEN_SSL=	base openssl30 openssl31
BROKEN_SSL_REASON=	error: undefined reference due to --no-allow-shlib-undefined: ERR_
.endif

.include <bsd.port.mk>
