# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	devnull@uptsoft.com
COMMENT=	Firewall Builder GUI and policy compilers

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		fwbuilder.5:${PORTSDIR}/security/libfwbuilder

CONFIGURE_SCRIPT= autogen.sh
# CONFIGURE_ARGS+=  --with-iconsdir=${X11BASE}/share/gnome/fwbuilder/pixmaps/ --with-templatedir=${X11BASE}/share/gnome/fwbuilder
# USE_AUTOCONF=   yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		fwbuilder.1 fwblookup.1 fwb_ipt.1 fwb_ipf.1 fwb_ipfw.1 fwb_pf.1 \
		fwb_install.1

post-extract:
	@${ECHO_CMD} "===! Running aclocal"
	@(cd ${WRKSRC}; aclocal; autoconf)

.include <bsd.port.mk>
