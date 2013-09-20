# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dhcperf
PORTVERSION=	1.0.1.0
CATEGORIES=	net benchmarks
MASTER_SITES=	ftp://ftp.nominum.com/pub/nominum/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1-freebsd-5.4-i386

MAINTAINER=	edwin@mavetju.org
COMMENT=	DHCPerf delivers accurate performance metrics of Dynamic Host Configuration Protocol service

LIB_DEPENDS=	c.5:${PORTSDIR}/misc/compat5x

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Rebuild of i386 package provided by Nominum.
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1/

PLIST_FILES=	bin/dhcperf \
		share/doc/dhcperf/dcsevaltutorial.pdf \
		share/doc/dhcperf/dhcperf.pdf
PLIST_DIRS=	share/doc/dhcperf
MAN1=		dhcperf.1

NO_STAGE=	yes
post-extract:
	${TAR} -C ${WRKSRC} -zxvf ${WRKSRC}/${PORTNAME}-${PORTVERSION}_1.tgz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/nom/bin/dhcperf ${PREFIX}/bin/dhcperf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/man/man1/dhcperf.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/share/doc/dhcperf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/doc/dhcperf/dcsevaltutorial.pdf ${PREFIX}/share/doc/dhcperf/dcsevaltutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/doc/dhcperf/dhcperf.pdf ${PREFIX}/share/doc/dhcperf/dhcperf.pdf

.include <bsd.port.mk>
