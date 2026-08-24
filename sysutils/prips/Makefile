PORTNAME=	prips
PORTVERSION=	1.3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://devel.ringlet.net/files/sys/prips/

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Prints IP subnet ranges by list or CIDR
WWW=		https://devel.ringlet.net/sysutils/prips/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSES/GPL-2.0-or-later.txt

MAKE_ENV=	PREFIX=${PREFIX} MANDIR=${PREFIX}/share/man/man

WRKSRC_SUBDIR=	c

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/../prips.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/changes.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/download.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../docs/index.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
