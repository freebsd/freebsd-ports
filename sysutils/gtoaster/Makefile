# New ports collection makefile for:	gtoaster
# Date created:				28 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	gtoaster
PORTVERSION=	2000092620
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@osd.bsdi.com

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

WRKSRC=		${WRKDIR}/gtoaster

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

post-install:
	strip ${PREFIX}/bin/gtoaster

.include <bsd.port.mk>
