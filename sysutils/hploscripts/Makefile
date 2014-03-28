# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hploscripts
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	sysutils perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	HP Lights-Out management perl scripts

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.19:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		shebangfix perl5
NO_BUILD=	yes
SHEBANG_FILES=	locfg.pl

PORTDOCS=	iLO_perl_xml.pdf linux-LOsamplescripts.txt

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/hponcfg_reformat.xsl ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/locfg.pl ${STAGEDIR}${PREFIX}/bin/locfg
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/iLO_perl_xml.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/linux-LOsamplescripts3.00.0-2.txt \
		${STAGEDIR}${DOCSDIR}/linux-LOsamplescripts.txt

regression-test: build
	@${PERL} -c ${WRKSRC}/locfg.pl

.include <bsd.port.mk>
