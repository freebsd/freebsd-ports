# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	pdumpfs
PORTVERSION=	1.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://0xcc.net/pdumpfs/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daily backup system similar to Plan9's dumpfs

LICENSE=	GPLv2

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/pdumpfs.in
ALL_TARGET=	pdumpfs

PLIST_FILES=	sbin/pdumpfs
PORTDOCS=	*
MANLANG=	"" ja
MAN8=		pdumpfs.8

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pdumpfs ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/man/man8/pdumpfs.8 ${PREFIX}/man/man8/
	${RUBY} -ni -r nkf -e 'puts NKF.nkf("-e",$$_)' ${WRKSRC}/man/ja/man8/pdumpfs.8
	${INSTALL_MAN} ${WRKSRC}/man/ja/man8/pdumpfs.8 ${PREFIX}/man/ja/man8/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc ${DOCSDIR}/
.endif

.include <bsd.port.mk>
