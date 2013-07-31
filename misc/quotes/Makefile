# Created by: Dima Sivachenko
# $FreeBSD$

PORTNAME=	quotes
DISTVERSION=	1.7-2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_TUCOWS} \
		http://freebsd.unixfreunde.de/sources/
MASTER_SITE_SUBDIR=	console/office

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quote, currency, and Slashdot headline fetcher based on Perl

NO_BUILD=	yes
USES=		shebangfix perl5
SHEBANG_FILES=	quotes quotesmailer QuExample.pm

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -i '' -e "s:/usr/local/lib/Quotes:${PREFIX}/etc:" \
		-e "s:/usr/local:${PREFIX}:" ${WRKSRC}/quotes

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/quotes ${PREFIX}/bin
	@ ${INSTALL_SCRIPT} ${WRKSRC}/quotesmailer ${PREFIX}/bin
	@ ${INSTALL_DATA} ${WRKSRC}/sample.quotesrc ${PREFIX}/etc/quotesrc.sample
.if ${PORT_OPTIONS:MDOCS}
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/quotes.txt ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/QuExample.pm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
