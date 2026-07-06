PORTNAME=	route-summarization
DISTVERSIONPREFIX=	v
DISTVERSION=	0.3.1
CATEGORIES=	net

MAINTAINER=	ports@brtsvcs.net
COMMENT=	Lightweight CIDR aggregator using Perl's Net::CIDR::Lite
WWW=		https://github.com/edmundlod/route-summarization

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Net-CIDR-Lite>=0:net/p5-Net-CIDR-Lite

USES=		perl5
USE_GITHUB=	yes
GH_ACCOUNT=	edmundlod

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/aggregateCIDR.pl ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA}	${WRKSRC}/README.md ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
