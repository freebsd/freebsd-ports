# New ports collection makefile for:	ipacctd
# Date created:		22 Aug 2003
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ipacctd
PORTVERSION=	1.47
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/ipacctd/ \
		${MASTER_SITE_LOCAL:S!$!skv/!}

MAINTAINER=	skv@FreeBSD.org
COMMENT=	IP accounting using divert socket

USE_RC_SUBR=	ipacctd

WRKSRC=		${WRKDIR}/${PORTNAME}
MAKE_ENV+=	BINDIR="${PREFIX}/sbin"

MAN8=		ipacctd.8
MANLANG=	"" ru.KOI8-R
MANCOMPRESSED=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${DOCSDIR}/ru
	@${INSTALL_DATA} ${WRKSRC}/README.ipacctd ${DOCSDIR}/ru
.endif

.include <bsd.port.mk>
