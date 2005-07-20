# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	2.0.8
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	vadim@fwbuilder.org
COMMENT=	Firewall Builder API

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.7:${PORTSDIR}/net-mgmt/net-snmp

USE_QT_VER=	3

QTDIR?=		${X11BASE}

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
INSTALLS_SHLIB=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-install:
	${RM} ${PREFIX}/lib/libfwbuilder.so.6.3
	${RM} ${PREFIX}/lib/libfwcompiler.so.6.3

.include <bsd.port.mk>
