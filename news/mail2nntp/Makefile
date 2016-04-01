# Created by: gary@hayers.org
# $FreeBSD$

PORTNAME=	mail2nntp
PORTVERSION=	1.0
CATEGORIES=	news mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/Stable%201.0/

MAINTAINER=	gary@hayers.org
COMMENT=	Simple mail to news gateway

LICENSE=	GPLv2

RUN_DEPENDS=	p5-NNTPClient>=0:news/p5-NNTPClient

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	mail2nntp.pl

PORTDOCS=	*
PLIST_FILES=	bin/mail2nntp.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mail2nntp.pl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
