# ex:ts=8
# New ports collection makefile for:	cgi++
# Date created:			Mar 26, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cgicc
PORTVERSION=	3.2.3
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	ftp://ftp.cgicc.org/

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A C++ class library for writing CGI applications

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	NOPORTDOCS=${NOPORTDOCS}
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-pedantic||g' ${WRKSRC}/configure

.include <bsd.port.mk>
