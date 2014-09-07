# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ipacctd
PORTVERSION=	1.47
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/ipacctd/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP accounting using divert socket

USES=		uidfix
USE_RC_SUBR=	ipacctd
MAKE_ENV=	BINDIR="${PREFIX}/sbin"

OPTIONS_DEFINE=	DOCS

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/ru
	${INSTALL_DATA} ${WRKSRC}/README.ipacctd ${STAGEDIR}${DOCSDIR}/ru

.include <bsd.port.mk>
