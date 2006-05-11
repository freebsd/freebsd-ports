# New ports collection makefile for: mrng-cfgtg-ping-probe
# Date created:         17 Jan 2004
# Whom:                 sanpei@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mrtg-ping-probe
PORTVERSION=	2.2.0
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pwo.de/pub/pwo/mrtg/${PORTNAME}/

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	A Round Trip Time and Packet Loss Probe for MRTG

RUN_DEPENDS=	${LOCALBASE}/bin/mrtg:${PORTSDIR}/net-mgmt/mrtg

USE_PERL5=	YES

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|%%PERL%%|${PERL5}|' ${WRKSRC}/${PORTNAME}
	@${CHMOD} +x ${WRKSRC}/${PORTNAME}

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mrtg-ping-cfg  ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/mrtg.cfg-ping  ${PREFIX}/etc/mrtg
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
