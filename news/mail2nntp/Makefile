# Created by: gary@hayers.org
# $FreeBSD$

PORTNAME=	mail2nntp
PORTVERSION=	1.0
CATEGORIES=	news mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Stable%201.0/

MAINTAINER=	gary@hayers.org
COMMENT=	Simple mail to news gateway

LICENSE=	GPLv2

RUN_DEPENDS=	p5-NNTPClient>=0:${PORTSDIR}/news/p5-NNTPClient

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

PORTDOCS=	*
PLIST_FILES=	bin/mail2nntp.pl

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mail2nntp.pl ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCSDIR}
.endif

.include <bsd.port.mk>
