# Ports collection makefile for:  libnet-devel
# Date created:			Jan 7, 2003
# Whom:				smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.1.3.r1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
PKGNAMESUFFIX=	${SHORT_VER}-devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r1$//}-RC-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for creating IP packets (development version)

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${SHORT_VER}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${SHORT_VER}

DOCS=		README doc/BUGS doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO
EXAMPLES=	sample/*.c

SHORT_VER=	113

USE_LDCONFIG=	${PREFIX}/lib/libnet${SHORT_VER}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config \
		${PREFIX}/bin/libnet${SHORT_VER}-config
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
	@cd ${PREFIX}/lib && \
		${LN} -sf libnet${SHORT_VER}/libnet.so libnet-1.1.3.so.1 && \
		${LN} -sf libnet-1.1.3.so.1 libnet-1.1.3.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
