# New ports collection makefile for:	hploscripts
# Date created:				11 Feb 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hploscripts
PORTVERSION=	2.40.0
CATEGORIES=	sysutils perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	HP Lights-Out management perl scripts

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.19:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	5.8.0+
NO_BUILD=	yes

PORTDOCS=	iLO_perl_xml.pdf linux-LOsamplescripts2.40.0-1.txt

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL}|' ${WRKSRC}/locfg.pl \
		${WRKSRC}/vspconfig.pl

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/hponcfg_reformat.xsl ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/iLO_perl_xml.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/linux-LOsamplescripts2.40.0-1.txt ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/locfg.pl ${PREFIX}/bin/locfg
	${INSTALL_SCRIPT} ${WRKSRC}/vspconfig.pl ${PREFIX}/bin/vspconfig

regression-test: build
	@${PERL} -c ${WRKSRC}/locfg.pl
	@${PERL} -c ${WRKSRC}/vspconfig.pl

.include <bsd.port.mk>
