# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	1.1.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder GUI and policy compilers

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		fwbuilder.5:${PORTSDIR}/security/libfwbuilder

USE_GNOME=	glib12 gtk12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=           fwbuilder.1 fwblookup.1 fwbedit.1 fwb_ipt.1 fwb_ipf.1 fwb_ipfw.1 fwb_pf.1 \
		fwb_install.1 fwb_compile_all.1

.include <bsd.port.mk>
