# New ports collection makefile for:	gicq
# Version required:			0.33
# Date Created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $Id: Makefile,v 1.4 1999/01/22 22:13:48 nectar Exp $
#

DISTNAME=	gicq-0.33
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/                        \
		http://www.nectar.com/distfiles/

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	gtk12.1:${PORTSDIR}/x11-toolkits/gtk12                 \
		icq.0:${PORTSDIR}/devel/libicq

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"

.include <bsd.port.mk>
