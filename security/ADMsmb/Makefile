# Ports collection makefile for:	ADMsmb
# Date created:			23 Jun 2003
# Whom:				tutus@trynet.eu.org
#
# $FreeBSD$
#

PORTNAME=	ADMsmb
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	http://www.geocities.com/bofn1001/ \
		${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	groups/ADM
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Security scanner for Samba

USE_REINPLACE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "*.o" -delete
	@${REINPLACE_CMD} -e 's|-O3|${CFLAGS}|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ADMsmb ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/ADMsmb
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/ADMsmb

.include <bsd.port.mk>
