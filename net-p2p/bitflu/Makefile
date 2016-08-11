# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bitflu
PORTVERSION=	1.51
CATEGORIES=	net-p2p
MASTER_SITES=	http://bitflu.workaround.ch/bitflu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BitTorrent client written in Perl

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/Documentation/artistic-2_0.txt

RUN_DEPENDS=	p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
		p5-Danga-Socket>=0:devel/p5-Danga-Socket

USES=		perl5 shebangfix tar:tgz
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	bitflu.pl
SUB_FILES=	pkg-message

PORTDOCS=	ChangeLog.txt README.txt README_IPv6.txt

OPTIONS_DEFINE=		DOCS EXAMPLES IPV6

IPV6_RUN_DEPENDS=	p5-IO-Socket-INET6>=0:net/p5-IO-Socket-INET6

post-patch:
	@${REINPLACE_CMD} -e 's|'\''.bitflu.config'\''|"$$ENV{HOME}/.bitflu.config"|; \
		s|\./plugins|${DATADIR}/plugins|; \
		s|\./workdir|$$ENV{HOME}/.bitflu.workdir|' \
		${WRKSRC}/bitflu.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}/plugins/Bitflu
	${INSTALL_DATA} ${WRKSRC}/plugins/Bitflu/*.pm ${STAGEDIR}${DATADIR}/plugins/Bitflu

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.config.example \
		${STAGEDIR}${EXAMPLESDIR}/${PORTNAME}.config

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
