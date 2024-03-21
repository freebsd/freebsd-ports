PORTNAME=	setaudit
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Tool to specify audit configurations on a process
WWW=		https://github.com/csjayp/setaudit

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	csjayp

PLIST_FILES=	bin/setaudit \
		share/man/man8/setaudit.8.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}/${PREFIX}/share/man/man8

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
