# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	2.1.14
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder API

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.10:${PORTSDIR}/net-mgmt/net-snmp

BUILD_VERSION=	21
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USE_QT_VER=	3

QTDIR?=		${QT_PREFIX}

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-install:
	${RM} ${PREFIX}/lib/libfwbuilder.so.7.3
	${RM} ${PREFIX}/lib/libfwcompiler.so.7.3

.include <bsd.port.mk>
