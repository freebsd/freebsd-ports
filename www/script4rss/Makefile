# Created by: ijliao
# $FreeBSD$

PORTNAME=	script4rss
PORTVERSION=	0.4b
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easily create scripts to convert HTML pages to RSS feeds

USES=		tar:bzip2 perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes

PLIST_FILES=	bin/script4rss
PORTEXAMPLES=	*
SHEBANG_FILES=	script4rss.pl

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script4rss.pl \
		${STAGEDIR}${PREFIX}/bin/script4rss
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
