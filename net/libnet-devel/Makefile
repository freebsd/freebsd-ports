# Ports collection makefile for:  libnet-devel
# Date created:			Jan 7, 2003
# Whom:				smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.1.1
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
PKGNAMESUFFIX=	-devel

MAINTAINER=	krion@FreeBSD.org
COMMENT=	A C library for creating IP packets (development version)

CONFLICTS=	libnet-1.*

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		README doc/BUGS doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO doc/html/*
EXAMPLES=	sample/*.c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
