# Created by: Yen-Ming Lee <leeym@cae.ce.ntu.edu.tw>
# $FreeBSD$

PORTNAME=	wakeonlan
PORTVERSION=	0.41
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://github.com/jpoliv/wakeonlan/archive/

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Sends magic packets to WOL enabled NIC to switch on the called PC

LICENSE=	ART20

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/lab001.wol ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
