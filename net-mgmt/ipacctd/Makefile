# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ipacctd
PORTVERSION=	1.47
CATEGORIES=	net-mgmt
MASTER_SITES=	LOCAL/skv

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP accounting using divert socket

LICENSE=	BSD2CLAUSE

USES=		uidfix
USE_RC_SUBR=	ipacctd
MAKE_ENV=	BINDIR="${PREFIX}/sbin"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} 's,{MANDIR},{DESTDIR}$$&,' ${WRKSRC}/man_ru/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ru
	${INSTALL_DATA} ${WRKSRC}/README.ipacctd ${STAGEDIR}${DOCSDIR}/ru

.include <bsd.port.mk>
