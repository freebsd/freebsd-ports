PORTNAME=	fd
PORTVERSION=	3.01j
PORTREVISION=	2
CATEGORIES=	shells net
MASTER_SITES=	http://www.unixusers.net/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	CUI-based file and directory management tool
WWW=		http://www.unixusers.net/authors/VA012337/soft/fd/index.html

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/LICENSES
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_LOCALE=	ja
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CONFDIR="\$$(DESTDIR)${PREFIX}/etc" \
		MANTOP="\$$(DESTDIR)${PREFIX}/share/man" \
		PREFIX="\$$(DESTDIR)${PREFIX}"

CONFLICTS_INSTALL=	fd-find # bin/fd

DOCS_EN=	FAQ.eng LICENSES.eng README.eng TECHKNOW.eng ToAdmin.eng
DOCS_JA=	FAQ HISTORY LICENSES README TECHKNOW ToAdmin

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_DATA} ${WRKSRC}/_fdrc.orig \
		${STAGEDIR}${PREFIX}/etc/fd2rc.dist
	${INSTALL_DATA} ${WRKSRC}/_fdrc ${STAGEDIR}${PREFIX}/etc/fd2rc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}
	${INSTALL_DATA} ${DOCS_EN:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} \
		${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}

.include <bsd.port.mk>
