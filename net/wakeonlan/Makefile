PORTNAME=	wakeonlan
PORTVERSION=	0.42
CATEGORIES=	net

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Sends magic packets to WOL enabled NIC to switch on the called PC
WWW=		https://github.com/jpoliv/wakeonlan

LICENSE=	ART20

USE_GITHUB=	yes
GH_ACCOUNT=	jpoliv
GH_TAGNAME=	4beb45d

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/lab001.wol ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
