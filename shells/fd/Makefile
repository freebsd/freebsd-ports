# Created by: Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
# $FreeBSD$

PORTNAME=	fd
PORTVERSION=	3.01b
CATEGORIES=	shells net
MASTER_SITES=	http://hp.vector.co.jp/authors/VA012337/soft/fd/ \
		ftp://ftp.unixusers.net/src/fdclone/
DISTNAME=	FD-${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	CUI-based file and directory management tool

OPTIONS_DEFINE=	DOCS

MAKE_ENV=	LANG=ja
MAKE_ARGS=	CC="${CC}" PREFIX="\$$(DESTDIR)${PREFIX}" CONFDIR="\$$(DESTDIR)${PREFIX}/etc"

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

BROKEN_powerpc=		Does not compile on powerpc: tzfile.h: No such file or directory

post-configure:
	${REINPLACE_CMD} -E -e 's|^(#[[:space:]]*define[[:space:]]+EXTENDCCOPT[[:space:]]+"([^"]+ )?)-O(["[:space:]])|\1${CFLAGS}\3|' ${WRKSRC}/machine.h

post-install:
	@${INSTALL_DATA} ${WRKSRC}/_fdrc.orig ${STAGEDIR}${PREFIX}/etc/fd2rc.dist
	@${INSTALL_DATA} ${WRKSRC}/_fdrc ${STAGEDIR}${PREFIX}/etc/fd2rc.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}
	@for i in ${DOCS_EN}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${DOCSDIR}; \
	done
	@for i in ${DOCS_JA}; do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${STAGEDIR}${PREFIX}/share/doc/ja/${PORTNAME}; \
	done

.include <bsd.port.mk>
