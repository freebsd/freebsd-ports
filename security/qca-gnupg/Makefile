# $FreeBSD$

PORTNAME=	qca-gnupg
DISTVERSION=	2.0.0-beta3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QCA GnuPG plugin

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

USE_BZIP2=	yes
USE_QT4=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--plugins-path=${PREFIX}/${QT_PLUGINDIR_REL}

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--release --no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=--debug
PLIST_SUB+=	DEBUG=""
.endif

NO_STAGE=	yes
post-install:
	${STRIP_CMD} ${PREFIX}/${QT_PLUGINDIR_REL}/crypto/libqca-gnupg.so

.include <bsd.port.mk>
