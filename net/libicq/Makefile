# New ports collection makefile for:	libicq
# Version required:			0.33
# Date Created:				31 Oct 1998
# Whom:					Seiichirou Hiraoka
#
# $Id: Makefile,v 1.3 1999/03/15 19:59:22 nectar Exp $
#

DISTNAME=	libicq-0.33
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.korsoft.com/pub/gicq/                        \
		http://www.nectar.com/distfiles/

MAINTAINER=	flathill@FreeBSD.ORG

LIB_DEPENDS=	glib12.1:${PORTSDIR}/devel/glib12

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GLIB_CONFIG="${PREFIX}/bin/glib12-config"

.include <bsd.port.mk>
