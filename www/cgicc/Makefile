# ex:ts=8
# New ports collection makefile for:	cgi++
# Date created:			Mar 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgicc
PORTVERSION=	3.2.3
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.cgicc.org/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A C++ class library for writing CGI applications

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=13
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
