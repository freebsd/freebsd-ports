# New ports collection makefile for:	easysoap
# Date created:			21th September 2001
# Whom:				Gabriel Ambuehl <gabriel_ambuehl@buz.ch>
#
# $FreeBSD$
#

PORTNAME=	easysoap
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	EasySoap++-${PORTVERSION}

MAINTAINER=    gabriel_ambuehl@buz.ch

LIB_DEPENDS=	expat.2:${PORTSDIR}/textproc/expat2

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lexpat"
INSTALLS_SHLIB=	yes

pre-patch:
	@${PERL} -pi -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/abyss/src/data.c
.include <bsd.port.mk>
