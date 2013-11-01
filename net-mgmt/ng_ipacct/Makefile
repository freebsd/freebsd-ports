# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	ng_ipacct
PORTVERSION=	20061223
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_LOCAL:S!$!skv/!} \
		http://highsecure.ru/distfiles/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	Netgraph IP accounting

LICENSE=	BSD

USES=	kmod

MAKE_ENV=	BINDIR="${PREFIX}/sbin" KMODDIR=${KMODDIR} NO_XREF=yes

USE_RC_SUBR=	ng_ipacct
SUB_FILES=	pkg-message
CFLAGS+=	-DMEM_USE_ZONE
NEED_ROOT=	yes

post-extract:
	@${MV} ${WRKDIR}/${PORTNAME} ${WRKSRC}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/netgraph
	${INSTALL_DATA} ${WRKSRC}/ng_ipacct/ng_ipacct.h ${STAGEDIR}${PREFIX}/include/netgraph
	${INSTALL_DATA} ${FILESDIR}/ng_ipacct.conf \
		${STAGEDIR}${PREFIX}/etc/ng_ipacct.conf.sample
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
