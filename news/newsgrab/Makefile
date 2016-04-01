# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	newsgrab
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Download and uudecode binary files from USENET using regexps

RUN_DEPENDS=	p5-NNTPClient>=0:news/p5-NNTPClient \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-News-Newsrc>=0:news/p5-News-Newsrc \
		p5-Time-modules>=0:devel/p5-Time-modules

NO_BUILD=	yes
USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	newsgrab.pl

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/newsgrab.pl ${STAGEDIR}${PREFIX}/bin/newsgrab
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/newsgrab
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/newsgrab
	${INSTALL_DATA} ${WRKSRC}/newsgrabrc ${STAGEDIR}${PREFIX}/share/doc/newsgrab

.include <bsd.port.mk>
