PORTNAME=	prips
PORTVERSION=	1.2.2
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/files/sys/prips/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR
WWW=		https://devel.ringlet.net/sysutils/prips/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL-2

MAKE_ENV=	PREFIX=${PREFIX} MANDIR=${PREFIX}/share/man/man

OPTIONS_DEFINE=	DOCS

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/changes.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/download.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/index.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
