PORTNAME=	tcping
PORTVERSION=	2.1.0
CATEGORIES=	net

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Do a TCP connect to the given IP/port combination
WWW=		https://github.com/mkirchner/tcping

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes

GH_ACCOUNT=	mkirchner

CFLAGS+=	-DHAVE_HSTRERROR

PLIST_FILES=	bin/tcping
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/tcping ${WRKSRC}/tcping.c ${WRKSRC}/cli.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcping ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
