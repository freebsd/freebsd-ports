# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	fwbuilder
PORTVERSION=	5.1.0
DISTVERSIONSUFFIX=	.${BUILD}
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/Current_Packages/${PORTVERSION}

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder GUI and policy compilers

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BROKEN_powerpc64=	fails to configure: libz library not found

LIB_DEPENDS=	libxslt.so:textproc/libxslt \
		libnetsnmp.so:net-mgmt/net-snmp

OPTIONS_DEFINE=	DOCS

BUILD=		3599

.if defined(PKGNAMESUFFIX) && ${PKGNAMESUFFIX} == -devel
CONFLICTS=	fwbuilder-[234].* fwbuilder-devel-[234].* \
		libfwbuilder-[234].* libfwbuilder-devel-[234].*
.else
CONFLICTS=	fwbuilder-[234].* fwbuilder-devel-* \
		libfwbuilder-[234].* libfwbuilder-devel-*
.endif

USES=		autoreconf:build gmake libtool qmake:no_configure qt:4 ssl
PLIST_SUB=	BUILD_VERSION=${PORTVERSION}.${BUILD}
USE_QT=		corelib \
		gui \
		iconengines \
		inputmethods \
		linguist_build \
		moc_build \
		rcc_build \
		qmake_build \
		svg \
		uic_build \
		xml

QTDIR?=		${PREFIX}

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		INSTALL_ROOT=${STAGEDIR}
CPPFLAGS+=	-I${LOCALBASE}/include
CXXFLAGS+=	-Wno-reserved-user-defined-literal
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR} --with-qtdir=${QTDIR} \
		--prefix=${PREFIX}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
MAKE_ENV=	INSTALL_ROOT=${STAGEDIR} CCACHE_DISABLE=yes
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

PORTDOCS=	*

.include <bsd.port.options.mk>

.if !exists (/usr/bin/rcs)
# IMPORTANT: Newer versions of rcs will NOT work with fwbuilder.
RUN_DEPENDS+=	rcs:devel/rcs57
.endif

.if empty(PORT_OPTIONS:MDOCS)
BROKEN=		DOCS must be enabled in this port
.endif

post-patch:
	@${REINPLACE_CMD} '/^\.\/configure/d' ${WRKSRC}/autogen.sh

pre-configure:
	(cd ${WRKSRC} && ./autogen.sh)

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fwbuilder
	@${ECHO} If you are upgrading from a previous version of fwbuilder,
	@${ECHO} please make sure to backup your fwbuilder database files
	@${ECHO} prior to invoking fwbuilder for the first time.

.include <bsd.port.mk>
