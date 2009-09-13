# ex:ts=8
# Ports collection makefile for:	xmlrpc++
# Date created:			Nov 13, 2003
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmlrpc++
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/xmlrpcpp/xmlrpc%2B%2B/Version%20${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ implementation of the XML-RPC protocol

DEPRECATED=	depends on old version of GCC, no maintainer, not used by any other port, dead upstream
EXPIRATION_DATE=2009-10-13

USE_GCC=	3.4
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|^CXX|#CXX|" -e "s|^CXXFLAGS|#CXXFLAGS|" \
		-e "s|tests$$||" ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/include/xmlrpc++
	${INSTALL_DATA} ${WRKSRC}/src/XmlRpc*.h ${PREFIX}/include/xmlrpc++
	${INSTALL_PROGRAM} ${WRKSRC}/libXmlRpc.a ${PREFIX}/lib

.include <bsd.port.mk>
