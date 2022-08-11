PORTNAME=	pflogsumm
PORTVERSION=	1.1.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/ \
		ftp://jimsun.LinxNet.com/pub/postfix_contrib/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Postfix Log Entry Summarizer

LICENSE=	GPLv2+

RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc

USES=		perl5 shebangfix
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/pflogsumm man/man1/pflogsumm.1.gz
SHEBANG_FILES=	${PORTNAME}.pl
PORTDOCS=	README ToDo pflogsumm-faq.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
