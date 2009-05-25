# New ports collection makefile for:	libfwbuilder
# Date Created:				27 May 2002
# Whom:					Sergey Lyubka <devnull@asitatech.ie>
#
# $FreeBSD$

PORTNAME=	libfwbuilder
PORTVERSION=	3.0.4
PORTREVISION=	2
CATEGORIES=	security
.if defined(BUILD)
MASTER_SITES=	http://www.fwbuilder.org/nightly_builds/fwbuilder-3.0/build-${BUILD}/
.else
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	fwbuilder
.endif

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Firewall Builder API

CONFLICTS=	libfwbuilder-2.*
LIB_DEPENDS=	xslt.2:${PORTSDIR}/textproc/libxslt \
		netsnmp.16:${PORTSDIR}/net-mgmt/net-snmp

PLIST_SUB=	BUILD_VERSION=${PORTVERSION}
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
	${RM} ${PREFIX}/lib/libfwbuilder.so.8.2
	${RM} ${PREFIX}/lib/libfwcompiler.so.8.2

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>
.if defined(NOPORTDOCS)
BROKEN=		NOPORTDOCS is incomplete in this port
.endif
.include <bsd.port.post.mk>
