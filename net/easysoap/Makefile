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

BROKEN_SSL=	openssl30 openssl31
BROKEN_SSL_REASON=	error: undefined reference due to --no-allow-shlib-undefined: ERR_
DEPRECATED=	Last release was in 2006

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool localbase ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_stdcpp_main=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

.include <bsd.port.mk>
