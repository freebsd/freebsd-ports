# New ports collection makefile for:	easysoap
# Date created:			21th September 2001
# Whom:				Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
# $FreeBSD$
#

PORTNAME=	easysoap
PORTVERSION=	0.6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=	gabriel_ambuehl@buz.ch
COMMENT=	C++ SOAP Library based on expat

LIB_DEPENDS=	expat.4:${PORTSDIR}/textproc/expat2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

pre-configure:
	@echo "CPPFLAGS=${CPPFLAGS} CXXFLAGS=${CXXFLAGS}"

.include <bsd.port.post.mk>
