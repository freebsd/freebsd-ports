# New ports collection makefile for:	ng_ipacct
# Date created:		30 Nov 2004
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ng_ipacct
PORTVERSION=	20050731
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/kernel/ng_ipacct/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Netgraph IP accounting

NO_PACKAGE=	"Depends on kernel"

OPTIONS=	MEM_ZONE "Use UMA zone allocator (5.x only)" off

PLIST_SUB+=	KMODDIR=${KMODDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV=	BINDIR="${PREFIX}/sbin"

MAN8=		ipacctctl.8
MANLANG=	ru.KOI8-R
MANCOMPRESSED=	yes

USE_RC_SUBR=	ng_ipacct.sh
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.ifdef WITH_MEM_ZONE
CFLAGS+=	-DMEM_USE_ZONE
.endif

post-install:
	@${MKDIR} ${PREFIX}/include/netgraph
	${INSTALL_DATA} ${WRKSRC}/ng_ipacct/ng_ipacct.h ${PREFIX}/include/netgraph
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf ${PREFIX}/etc/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
