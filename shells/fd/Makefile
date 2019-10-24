# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	fd
PORTVERSION=	3.01j
CATEGORIES=	shells net
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	CUI-based file and directory management tool

USE_LOCALE=	ja
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" \
		PREFIX="\$$(DESTDIR)${PREFIX}" \
		CONFDIR="\$$(DESTDIR)${PREFIX}/etc" \

DOCS_EN=	FAQ.eng \
		LICENSES.eng \
		README.eng \
		TECHKNOW.eng \
		ToAdmin.eng
DOCS_JA=	FAQ \
		HISTORY \
		LICENSES \
		README \
		TECHKNOW \
		ToAdmin

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
