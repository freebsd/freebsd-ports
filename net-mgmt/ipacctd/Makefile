# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ipacctd
PORTVERSION=	1.47
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/ipacctd/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IP accounting using divert socket

USE_RC_SUBR=	ipacctd

MAKE_ENV+=	BINDIR="${PREFIX}/sbin"

MAN8=		ipacctd.8
MANLANG=	"" ru.KOI8-R
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/ru
	@${INSTALL_DATA} ${WRKSRC}/README.ipacctd ${DOCSDIR}/ru
.endif

.include <bsd.port.mk>
