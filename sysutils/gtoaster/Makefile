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

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

WRKSRC=		${WRKDIR}/gtoaster

GNU_CONFIGURE=	yes
USE_GTK=	yes
USE_GMAKE=	yes

post-install:
	strip ${PREFIX}/bin/gtoaster

.include <bsd.port.mk>
