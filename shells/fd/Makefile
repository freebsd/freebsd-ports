PORTNAME=	fd
PORTVERSION=	3.01j
PORTREVISION=	3
CATEGORIES=	shells net
MASTER_SITES=	http://www.unixusers.net/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	CUI-based file and directory management tool
WWW=		http://www.unixusers.net/authors/VA012337/soft/fd/index.html

LICENSE=	FDclone
LICENSE_NAME=	FDclone
LICENSE_FILE=	${WRKSRC}/LICENSES
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		iconv

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		CONFDIR="${PREFIX}/etc" \
		LANG=ja \
		MANTOP="${MANDIRS}" \
		PREFIX="${PREFIX}"
DESTDIRNAME=	BUILD

CONFLICTS_INSTALL=	fd-find # bin/fd

DOCS_JA=	FAQ HISTORY LICENSES README TECHKNOW ToAdmin

OPTIONS_DEFINE=	DOCS

post-build:
	${ICONV_CMD} -f EUC-JP -t UTF-8 ${WRKSRC}/fd.1 | \
		${GZIP_CMD} > ${WRKSRC}/fd.1.gz

post-install:
	${INSTALL_DATA} ${WRKSRC}/_fdrc.orig \
		${STAGEDIR}${PREFIX}/etc/fd2rc.dist
	${INSTALL_DATA} ${WRKSRC}/_fdrc ${STAGEDIR}${PREFIX}/etc/fd2rc.sample
	@${MKDIR} ${STAGEDIR}${MANDIRS}/ja.UTF-8/man1
	${INSTALL_MAN} ${WRKSRC}/fd.1.gz ${STAGEDIR}${MANDIRS}/ja.UTF-8/man1
	cd ${STAGEDIR}${MANDIRS}/ja.UTF-8/man1 && ${LN} fd.1.gz fdsh.1.gz

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ja
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,:S,$,.eng,} \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS_JA:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/ja

.include <bsd.port.mk>
