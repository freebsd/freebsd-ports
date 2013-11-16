# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	libnet
PORTVERSION=	1.0.2a
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	http://www.packetfactory.net/libnet/dist/deprecated/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
PKGNAMESUFFIX=	10

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A C library for creating IP packets

CFLAGS+=	-fPIC

USE_AUTOTOOLS=	autoconf
WRKSRC=		${WRKDIR}/Libnet-${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}
MAN3=		libnet${PKGNAMESUFFIX}.3

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e 's|bpf0|null|' ${WRKSRC}/configure
.if ${ARCH} == "amd64"
	find ${WRKDIR} -name '*.[hc]' | xargs ${REINPLACE_CMD} -e 's/long/int/g'
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/libnet.3 \
		${STAGEDIR}${MANPREFIX}/man/man3/libnet${PKGNAMESUFFIX}.3
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ancillary ${STAGEDIR}${DOCSDIR}/examples
.for i in CHANGELOG CHANGELOG-NEWFUNCTIONS COPYING README TODO-1.0 TODO-1.1
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.for i in README.asn.1 README.bpf README.legacy-applications README.libnet-config README.linux README.rawsockets
	${INSTALL_DATA} ${WRKSRC}/doc/Ancillary/${i} ${STAGEDIR}${DOCSDIR}/ancillary/
.endfor
.for i in libnet-example-1.c libnet-example-2.c libnet-example-3.c libnet-example-4.c
	${INSTALL_DATA} ${WRKSRC}/example/${i} ${STAGEDIR}${DOCSDIR}/examples/
.endfor
.endif

.include <bsd.port.mk>
