# Created by: Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
# $FreeBSD$

PORTNAME=	easysoap
PORTVERSION=	0.8.0
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SWANSONG
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ SOAP Library based on expat

LICENSE=	LGPL21

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		libtool ssl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_lib_stdcpp_main=no
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	use of undeclared identifier 'SSLv2_client_method'
BROKEN_FreeBSD_13=	use of undeclared identifier 'SSLv2_client_method'
.endif

.include <bsd.port.post.mk>
