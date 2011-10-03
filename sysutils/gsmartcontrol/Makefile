# New ports collection makefile for:	gsmartcontrol
# Date created:		2009-03-25
# Whom:			Pawel Pekala <c0rn@o2.pl>
#
# $FreeBSD$
#

PORTNAME=		gsmartcontrol
PORTVERSION=		0.8.6
PORTREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Graphical user interface for smartmontools

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		pcre:${PORTSDIR}/devel/pcre
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		smartctl:${PORTSDIR}/sysutils/smartmontools

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	pkgconfig
INSTALLS_ICONS=	yes

MAN1=		gsmartcontrol.1

CONFIGURE_ARGS=	--disable-libglade

post-patch:
.if defined(NOPORTDOCS)
EXTRA_PATCHES+=	${PATCHDIR}/extra-Makefile.in
.endif

.include <bsd.port.mk>
