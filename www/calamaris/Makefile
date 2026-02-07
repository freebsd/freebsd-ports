PORTNAME=	calamaris
PORTVERSION=	2.59
PORTREVISION=	3
CATEGORIES=	www textproc
MASTER_SITES=	http://cord.de/files/calamaris/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl script to produce statistics out of Squid log files
WWW=		https://Cord.de/tools/squid/calamaris/

LICENSE=	GPLv2

CONFLICTS_INSTALL=	calamaris-devel

USES=		shebangfix perl5
NO_BUILD=	yes
SHEBANG_FILES=	calamaris

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
