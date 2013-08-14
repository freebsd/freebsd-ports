# Created by: Manuel Creach <manuel.creach@icloud.com>
# $FreeBSD$

PORTNAME=	libcec
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	GH

MAINTAINER=	manuel.creach@icloud.com
COMMENT=	Library to control Pulse-Eight's HDMI-CEC adapter

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Pulse-Eight
GH_COMMIT=	54be21e
GH_TAGNAME=	${PORTNAME}-${PORTVERSION}

USES=		pathfix pkgconfig
PATHFIX_MAKEFILEIN=Makefile.am
USE_AUTOTOOLS=	aclocal autoheader automake autoconf libtoolize
ACLOCAL_ARGS=	-I.
AUTOMAKE_ARGS=	--add-missing
USE_LDCONFIG=	yes

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
