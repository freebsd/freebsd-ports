# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	quotes
DISTVERSION=	1.7-2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quote, currency, and Slashdot headline fetcher based on Perl

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	quotes quotesmailer QuExample.pm

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -i '' -e "s:/usr/local/lib/Quotes:${PREFIX}/etc:" \
		-e "s:/usr/local:${PREFIX}:" ${WRKSRC}/quotes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/quotes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/quotesmailer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/sample.quotesrc ${STAGEDIR}${PREFIX}/etc/quotesrc.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/quotes.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/QuExample.pm ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
