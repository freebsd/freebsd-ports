PORTNAME=	gitup
DISTVERSION=	1.0
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Minimalist, dependency-free program to clone/pull Git repositories
WWW=		https://github.com/johnmehr/gitup

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl
USE_GITHUB=	yes
GH_ACCOUNT=	johnmehr

MAKE_ENV+=	CONFIG_FILE_PATH=${LOCALBASE}/etc/gitup.conf

SUB_FILES=	pkg-message
PLIST_FILES=	bin/gitup \
		"@sample etc/gitup.conf.sample" \
		share/man/man1/gitup.1.gz \
		share/man/man5/gitup.conf.5.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/gitup.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/gitup.conf.5 \
		${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_DATA} ${WRKSRC}/gitup.conf \
		${STAGEDIR}${PREFIX}/etc/gitup.conf.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
