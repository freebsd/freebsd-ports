# New ports collection makefile for:		evolution-sharp
# Date created:					20041012
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.21 2005/12/03 04:03:17 tmclau02 Exp $
#

PORTNAME=	evolution-sharp
PORTVERSION=	0.10.2
PORTREVISION=	2
CATEGORIES=	mail gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.10

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono bindings for evolution

BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		evolution:${PORTSDIR}/mail/evolution
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		evolution:${PORTSDIR}/mail/evolution

USE_GNOME=	gnomehack evolutiondataserver
USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	libtool:15
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
