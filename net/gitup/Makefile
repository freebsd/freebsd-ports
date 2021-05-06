PORTNAME=	gitup
DISTVERSION=	0.92
CATEGORIES=	net

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Minimalist, dependency-free program to clone/pull git repositories

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ssl

USE_GITHUB=	yes
GH_ACCOUNT=	johnmehr

MAKE_ENV+=	CONFIG_FILE_PATH=${LOCALBASE}/etc/gitup.conf

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
