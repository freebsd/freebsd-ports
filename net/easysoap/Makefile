# Created by: Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
# $FreeBSD$

PORTNAME=	easysoap
PORTVERSION=	0.8.0
PORTREVISION=	4
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/SWANSONG
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ SOAP Library based on expat

LICENSE=	LGPL21

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USE_OPENSSL=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_lib_stdcpp_main=no
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
