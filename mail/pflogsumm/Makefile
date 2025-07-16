PORTNAME=	pflogsumm
PORTVERSION=	1.1.11
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://jimsun.LinxNet.com/downloads/ \
		ftp://jimsun.LinxNet.com/pub/postfix_contrib/

MAINTAINER=	flo@FreeBSD.org
COMMENT=	Postfix Log Entry Summarizer
WWW=		https://jimsun.LinxNet.com/postfix_contrib.html

LICENSE=	GPLv2+

RUN_DEPENDS=	p5-Date-Calc>=0:devel/p5-Date-Calc

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/pflogsumm share/man/man1/pflogsumm.1.gz
PORTDOCS=	README ToDo pflogsumm-faq.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/$i ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
