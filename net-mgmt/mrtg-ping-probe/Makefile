# Created by: sanpei@FreeBSD.org
# $FreeBSD$

PORTNAME=	mrtg-ping-probe
PORTVERSION=	2.2.0
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	https://opsec.eu/src/

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Round Trip Time and Packet Loss Probe for MRTG

RUN_DEPENDS=	${LOCALBASE}/bin/mrtg:net-mgmt/mrtg

FETCH_BEFORE_ARGS=	-p      # MASTER_SITE needs PASSIVE FTP.

USES=		perl5 shebangfix
SHEBANG_FILES=	mrtg-ping-probe

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/mrtg-ping-cfg  ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/mrtg
	@${INSTALL_DATA} ${WRKSRC}/mrtg.cfg-ping  ${STAGEDIR}${PREFIX}/etc/mrtg
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
