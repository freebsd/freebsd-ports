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
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmlrpcpp
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ implementation of the XML-RPC protocol

USE_GCC=	3.4
USE_GMAKE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 501103
# Work around bsd.port.mk bug: Does not currently set up MAKE_ENV for gcc 3.2 and 3.3
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^CXX|#CXX|" -e "s|^CXXFLAGS|#CXXFLAGS|" \
		-e "s|tests$$||" ${WRKSRC}/Makefile

do-install:
	${MKDIR} ${PREFIX}/include/xmlrpc++
	${INSTALL_DATA} ${WRKSRC}/src/XmlRpc*.h ${PREFIX}/include/xmlrpc++
	${INSTALL_PROGRAM} ${WRKSRC}/libXmlRpc.a ${PREFIX}/lib

.include <bsd.port.post.mk>
