# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	2.0.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder GUI and policy compilers

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	fwbuilder.6:${PORTSDIR}/security/libfwbuilder
.if !exists(/usr/include/getopt.h)
LIB_DEPENDS+=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.endif

USE_QT_VER=	3

QTDIR?=		${X11BASE}

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR} --with-qtdir=${QTDIR}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		fwbuilder.1 \
		fwblookup.1 \
		fwbedit.1 \
		fwb_compile_all.1 \
		fwb_install.1 \
		fwb_ipt.1 \
		fwb_ipf.1 \
		fwb_ipfw.1 \
		fwb_pf.1

.include <bsd.port.mk>
