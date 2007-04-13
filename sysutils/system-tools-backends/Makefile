# New ports collection makefile for:	system-tools-backends
# Date created:				11 February 2005
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/system-tools-backends/Makefile,v 1.34 2007/03/12 12:25:41 ahze Exp $
#

PORTNAME=	system-tools-backends
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Backend system admin scripts for gnome-system-tools

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DBus.pm:${PORTSDIR}/devel/p5-Net-DBus
LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DBus.pm:${PORTSDIR}/devel/p5-Net-DBus

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_GNOME=	gnomehack intlhack glib20
GNU_CONFIGURE=	yes
USE_RC_SUBR=	system-tools-backends
USE_GNOME_SUBR=	yes
CONFIGURE_ARGS=	--with-stb-group=wheel \
		--localstatedir=/var
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} <= 500800
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
.endif

.include <bsd.port.post.mk>
