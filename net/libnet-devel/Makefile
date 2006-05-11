# Ports collection makefile for:  libnet-devel
# Date created:			Jan 7, 2003
# Whom:				smace@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	libnet
PORTVERSION=	1.1.3.r1
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r1$//}-RC-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for creating IP packets (development version)

CONFLICTS=	libnet*-1.*

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		README doc/BUGS doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO
EXAMPLES=	sample/*.c

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	${REINPLACE_CMD} -e "s|stdint.h|inttypes.h|g" \
		${WRKSRC}/include/libnet/libnet-types.h
.else
	${DO_NADA}
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
