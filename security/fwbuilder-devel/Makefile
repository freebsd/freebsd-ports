# New ports collection makefile for:	fwbuilder
# Date Created:				3 Feb 2001
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	fwbuilder
DISTVERSION=	4.0.0
PORTVERSION=	${DISTVERSION}
BUILD=		2877
CATEGORIES=	security
.if defined(BUILD)
MASTER_SITES=	http://www.fwbuilder.org/nightly_builds/fwbuilder-4.0/build-${BUILD}/
PKGNAMESUFFIX=	-devel
PORTVERSION=	${DISTVERSION}.b${BUILD}
.else
MASTER_SITES=	SF/${PORTNAME}/Current_Packages/${PORTVERSION}
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder GUI and policy compilers

.if defined(BUILD)
CONFLICTS=	fwbuilder-[23].* fwbuilder-devel-[23].*
LIB_DEPENDS=	fwbuilder.9:${PORTSDIR}/security/libfwbuilder-devel
.else
CONFLICTS=	fwbuilder-[23].* fwbuilder-devel-*
LIB_DEPENDS=	fwbuilder.9:${PORTSDIR}/security/libfwbuilder
.endif

PLIST_SUB=	BUILD_VERSION=${DISTVERSION}
USE_QT_VER=	4
QT_COMPONENTS=	corelib \
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

QTDIR?=		${QT_PREFIX}

USE_OPENSSL=	yes
USE_GMAKE=	yes
CONFIGURE_SCRIPT=	autogen.sh
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS+=	--with-docdir=${DOCSDIR} --with-qtdir=${QTDIR}
MAKE_ARGS+=	QTDIR="${QTDIR}" \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

MAN1=		fwbuilder.1 \
		fwbedit.1 \
		fwb_iosacl.1 \
		fwb_ipt.1 \
		fwb_ipf.1 \
		fwb_ipfw.1 \
		fwb_pix.1 \
		fwb_pf.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} >= 800107
MAKE_ENV+=	CCACHE_DISABLE=yes
.endif

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/fwbuilder
	@${ECHO} If you are upgrading from a previous version of fwbuilder,
	@${ECHO} please make sure to backup your fwbuilder database files
	@${ECHO} prior to invoking fwbuilder for the first time.

.if defined(NOPORTDOCS)
BROKEN=		NOPORTDOCS is incomplete in this port
.endif
.include <bsd.port.post.mk>
