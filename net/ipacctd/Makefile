# New ports collection makefile for:	ipacctd
# Date created:		22 Aug 2003
# Whom:			Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	ipacctd
PORTVERSION=	1.46
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wuppy.net.ru/pub/FreeBSD/local/ipacctd/

MAINTAINER=	skv@FreeBSD.org
COMMENT=	IP accounting using divert socket

STARTUP_SCRIPT=	ipacctd.sh.sample
PLIST_SUB=	STARTUP_SCRIPT=${STARTUP_SCRIPT}

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
	${INSTALL_SCRIPT} ${FILESDIR}/${STARTUP_SCRIPT} \
			${PREFIX}/etc/rc.d/${STARTUP_SCRIPT}

.include <bsd.port.mk>
