# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder GUI and policy compilers

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk-- \
		fwbuilder.5:${PORTSDIR}/security/libfwbuilder

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
WANT_AUTOMAKE_VER=	15
CONFIGURE_SCRIPT=	autogen.sh
CONFIGURE_ARGS=		--with-docdir=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GNOME=	glib12 gtk12 gdkpixbuf
INSTALLS_SHLIB=	yes

MAN1=		fwbuilder.1 fwblookup.1 fwbedit.1 fwb_ipt.1 fwb_ipf.1 fwb_ipfw.1 fwb_pf.1 \
		fwb_install.1 fwb_compile_all.1

post-patch:
	@${ECHO_MSG} "===! Running aclocal"
	cd ${WRKSRC} && aclocal && autoconf

.include <bsd.port.mk>
