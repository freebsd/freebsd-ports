# Ports collection makefile for:	pdumpfs
# Date created:			30 April 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pdumpfs
PORTVERSION=	0.6
CATEGORIES=	sysutils
MASTER_SITES=	http://namazu.org/~satoru/pdumpfs/

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/pdumpfs
DOCS_EN=	ChangeLog pdumpfs-en.html
DOCS_JA=	pdumpfs-ja.html

MANLANG=	"" ja
MAN8=		pdumpfs.8

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${PREFIX}/man/man8/
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${PREFIX}/man/ja/man8/
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${PREFIX}/share/doc/${PORTNAME}/ja/
.endfor
.endif

.include <bsd.port.mk>
