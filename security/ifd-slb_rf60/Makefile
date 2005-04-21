# New ports collection makefile for:   slb_rf60
# Date created:                20 Feb 2003
# Whom:                        Toni Andjelkovic <toni@soth.at>
#
# $FreeBSD$
#

PORTNAME=	ifd-slb_rf60
PORTVERSION=	2.2.0
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://www.linuxnet.com/drivers/readers/files/
DISTNAME=	${PORTNAME:S/^ifd-//}-drv-${PORTVERSION}

MAINTAINER=	toni@soth.at
COMMENT=	PC/SC Lite driver for the Reflex 62 serial smart card reader

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

USE_GMAKE=	yes
CFLAGS+=	-fPIC

PKGMESSAGE=	${WRKDIR}/pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/^ifd-//}

PORTDOCS=	README
PLIST_FILES=	lib/pcsc/drivers/libslb_rf60.so

do-install:
	${MKDIR} ${PREFIX}/lib/pcsc/drivers/
	${INSTALL_DATA} ${WRKSRC}/libslb_rf60.so \
		${PREFIX}/lib/pcsc/drivers/libslb_rf60.so

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${SED} 's,%%PREFIX%%,${PREFIX},g' < ${FILESDIR}/pkg-message.in > \
		${WRKDIR}/pkg-message
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
