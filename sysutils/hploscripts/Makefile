# New ports collection makefile for:	hploscripts
# Date created:				11 Feb 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hploscripts
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	HP Lights-Out management perl scripts

BUILD_DEPENDS=	p5-IO-Socket-SSL>=1.19:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	5.8.0+
NO_BUILD=	yes

PORTDOCS=	iLO_perl_xml.pdf linux-LOsamplescripts.txt

post-patch:
	@${REINPLACE_CMD} -e '1s|.*|#!${PERL}|' ${WRKSRC}/locfg.pl

do-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/hponcfg_reformat.xsl ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/locfg.pl ${PREFIX}/bin/locfg
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/iLO_perl_xml.pdf ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/linux-LOsamplescripts3.00.0-2.txt ${DOCSDIR}/linux-LOsamplescripts.txt
.endif

regression-test: build
	@${PERL} -c ${WRKSRC}/locfg.pl

.include <bsd.port.mk>
