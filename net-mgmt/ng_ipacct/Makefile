# New ports collection makefile for:	ng_ipacct
# Date created:		30 Nov 2004
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ng_ipacct
PORTVERSION=	20061223
CATEGORIES=	net-mgmt kld
MASTER_SITES=	${MASTER_SITE_LOCAL:S!$!skv/!} \
		ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/kernel/ng_ipacct/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Netgraph IP accounting

.ifndef PACKAGE_BUILDING
NO_PACKAGE=	Depends on kernel
.else
IGNORE=		Depends on kernel
.endif

OPTIONS=	MEM_ZONE "Use UMA zone allocator (>= 5.x only)" on

KMODDIR=	/boot/modules
PLIST_SUB+=	KMODDIR=${KMODDIR:S!^/!!}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ENV=	BINDIR="${PREFIX}/sbin" KMODDIR=${KMODDIR}

MAN8=		ipacctctl.8
MANLANG=	ru.KOI8-R
MANCOMPRESSED=	yes

USE_RC_SUBR=	ng_ipacct
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.ifdef WITH_MEM_ZONE
CFLAGS+=	-DMEM_USE_ZONE
.endif

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
	@${MKDIR} ${PREFIX}/include/netgraph
	${INSTALL_DATA} ${WRKSRC}/ng_ipacct/ng_ipacct.h ${PREFIX}/include/netgraph
	${INSTALL_DATA} ${FILESDIR}/ng_ipacct.conf \
		${PREFIX}/etc/ng_ipacct.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
