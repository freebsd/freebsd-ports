# New ports collection makefile for:	easysoap
# Date created:			21th September 2001
# Whom:				Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
# $FreeBSD$
#

PORTNAME=	easysoap
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	gabriel_ambuehl@buz.ch
COMMENT=	C++ SOAP Library based on expat

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes
USE_GCC=	2.95

pre-configure:
	@${ECHO_MSG} "CPPFLAGS=${CPPFLAGS} CXXFLAGS=${CXXFLAGS}"

post-install:
	@${RM} -f ${PREFIX}/lib/libeasysoap.la

.include <bsd.port.mk>
