# Created by: Yoshihiko Sarumaru <mistral@imasy.or.jp>
# $FreeBSD$

PORTNAME=	du2ps
PORTVERSION=	3.1
CATEGORIES=	sysutils
MASTER_SITES=	http://line.to/mac/soft/du2ps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Filter for converting output of du to PostScript file

# Nkf is required for just converting character code of japanese manual
BUILD_DEPENDS=	nkf:japanese/nkf

USES=		tar:tgz
ALL_TARGET=	# empty
MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/du2ps man/ja/man1/du2ps.1.gz man/man1/du2ps.1.gz
PORTDOCS=	README.ver1 README.ver2 README.xdu du2ps.pdf du2psj.pdf

OPTIONS_DEFINE=	DOCS

post-build:
	@nkf -e ${WRKSRC}/du2ps.1j > ${WRKSRC}/du2ps.1.ja

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/du2ps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/du2ps.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/du2ps.1.ja \
		${STAGEDIR}${MANPREFIX}/man/ja/man1/du2ps.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
