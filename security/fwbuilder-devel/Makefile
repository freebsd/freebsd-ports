# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	1.0.10
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder GUI and policy compilers

BUILD_DEPENDS=  autoconf:${PORTSDIR}/devel/autoconf \
		aclocal:${PORTSDIR}/devel/automake
LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf \
		fwbuilder.5:${PORTSDIR}/security/libfwbuilder

CONFIGURE_SCRIPT= autogen.sh
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_GTK=	yes
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=           fwbuilder.1 fwblookup.1 fwb_ipt.1 fwb_ipf.1 fwb_ipfw.1 fwb_pf.1 \
		fwb_install.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=  ${FILESDIR}/CertDruidP30Dialog.cc-patch
.endif

post-patch:
	@${ECHO_CMD} "===! Running aclocal"
	@(cd ${WRKSRC}; aclocal; autoconf)

.include <bsd.port.post.mk>
