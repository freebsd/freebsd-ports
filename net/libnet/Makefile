# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.1.2.1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	11

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A C library for creating IP packets

GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
USE_CSTD=	gnu89

WRKSRC=		${WRKDIR}/${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
EXAMPLESDIR=	${PREFIX}/share/examples/${PORTNAME}${PKGNAMESUFFIX}

DOCS=		README doc/BUGS doc/CHANGELOG doc/CONTRIB doc/COPYING \
		doc/DESIGN_NOTES doc/MIGRATION doc/PACKET_BUILDING doc/PORTED \
		doc/RAWSOCKET_NON_SEQUITUR doc/TODO doc/html/*
EXAMPLES=	sample/*.c

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libnet-config \
		${PREFIX}/bin/libnet${PKGNAMESUFFIX}-config
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
