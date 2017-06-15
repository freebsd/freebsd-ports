# Created by: Edwin Groothuis (edwin@mavetju.org)
# $FreeBSD$

PORTNAME=	dhcperf
PORTVERSION=	1.0.1.0
CATEGORIES=	net benchmarks
MASTER_SITES=	ftp://ftp.nominum.com/pub/nominum/${PORTNAME}/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1-freebsd-5.4-i386

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DHCPerf delivers accurate performance metrics of Dynamic Host Configuration Protocol service

LIB_DEPENDS=	libc.so.5:misc/compat5x

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	Rebuild of i386 package provided by Nominum.
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1/

PLIST_FILES=	bin/dhcperf \
		share/doc/dhcperf/dcsevaltutorial.pdf \
		share/doc/dhcperf/dhcperf.pdf man/man1/dhcperf.1.gz

post-extract:
	${TAR} -C ${WRKSRC} -zxvf ${WRKSRC}/${PORTNAME}-${PORTVERSION}_1.tgz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/nom/bin/dhcperf \
		${STAGEDIR}${PREFIX}/bin/dhcperf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/man/man1/dhcperf.1 \
		${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/dhcperf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/doc/dhcperf/dcsevaltutorial.pdf \
		 ${STAGEDIR}${PREFIX}/share/doc/dhcperf/dcsevaltutorial.pdf
	${INSTALL_DATA} ${WRKSRC}/usr/local/nom/doc/dhcperf/dhcperf.pdf \
		${STAGEDIR}${PREFIX}/share/doc/dhcperf/dhcperf.pdf

.include <bsd.port.mk>
