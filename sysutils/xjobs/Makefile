PORTNAME=	xjobs
PORTVERSION=	20200726
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.maier-komor.de/xjobs/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Utility reads job descriptions line by line and executes in parallel
WWW=		https://www.maier-komor.de/xjobs.html

LICENSE=	GPLv2

USES=		tar:tgz gmake

GNU_CONFIGURE=	yes
PLIST_FILES=	bin/xjobs share/man/man1/xjobs.1.gz

PORTDOCS=	ChangeLog README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
. endfor

.include <bsd.port.mk>
