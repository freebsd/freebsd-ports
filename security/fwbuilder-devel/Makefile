# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
PORTVERSION=	2.1.16
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}/fwbuilder/
MASTER_SITE_SUBDIR=	fwbuilder

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder GUI and policy compilers

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	fwbuilder.7:${PORTSDIR}/security/libfwbuilder

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
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR} --with-qtdir=${QTDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		fwbuilder.1 \
		fwblookup.1 \
		fwbedit.1 \
		fwb_ipt.1 \
		fwb_ipf.1 \
		fwb_ipfw.1 \
		fwb_pf.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.mk>
