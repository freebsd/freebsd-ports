# New ports collection makefile for:	gtoaster
# Date created:				28 September 2000
# Whom:					eric
#
# $FreeBSD$
#

PORTNAME=	gtoaster
PORTVERSION=	2001033113
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://gnometoaster.rulez.org/archive/
DISTNAME=	${PORTNAME}${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	eric@FreeBSD.org

RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

WRKSRC=		${WRKDIR}/gtoaster

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${X11BASE}
CONFIGURE_ENV=	GTK_CONFIG=${X11BASE}/bin/gtk12-config

USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

.include <bsd.port.mk>
