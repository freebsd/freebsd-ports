# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
DISTVERSION=	4.0.1
PORTVERSION=	${DISTVERSION}
PORTREVISION=	1
BUILD=		2929
CATEGORIES=	security

.if defined(BUILD)
MASTER_SITES=	http://www.fwbuilder.org/nightly_builds/fwbuilder-4.0/build-${BUILD}/ \
		http://www.komquats.com/distfiles/
PKGNAMESUFFIX=	-devel
PORTVERSION=	${DISTVERSION}.b${BUILD}
.else
MASTER_SITES=	SF/fwbuilder/Current_Packages/${PORTVERSION} \
		http://www.komquats.com/distfiles/
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder API

.if defined(BUILD)
CONFLICTS=	libfwbuilder-[23].* libfwbuilder-devel-[23].*
.else
CONFLICTS=	libfwbuilder-[23].* libfwbuilder-devel-*
.endif

LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.20:${PORTSDIR}/net-mgmt/net-snmp

PLIST_SUB=	BUILD_VERSION=${DISTVERSION}
USE_QT_VER=	4
QT_COMPONENTS=	corelib \
		gui \
		iconengines \
		inputmethods \
		linguist_build \
		moc_build \
		qmake_build \
		svg \
		uic_build \
		xml

QTDIR?=		${QT_PREFIX}

USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:262 aclocal:110 libtool:22
CONFIGURE_SCRIPT=	autogen.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-install:
	${RM} ${PREFIX}/lib/libfwbuilder.so.9.1
	${RM} ${PREFIX}/lib/libfwcompiler.so.9.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 800107
MAKE_ENV+=	CCACHE_DISABLE=yes
.endif

.if defined(NOPORTDOCS)
BROKEN=		NOPORTDOCS is incomplete in this port
.endif
.include <bsd.port.post.mk>
