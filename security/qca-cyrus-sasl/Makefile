# New ports collection makefile for:	qca-cyrus-sasl
# Date created:		2009-03-19
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qca-cyrus-sasl
DISTVERSION=	2.0.0-beta3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	QCA Cyrus SASL plugin

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca \
		sasl2:${PORTSDIR}/security/cyrus-sasl2

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--plugins-path=${PREFIX}/${QT_PLUGINDIR_REL} \
		--with-sasl-inc=${LOCALBASE}/include \
		--with-sasl-lib=${LOCALBASE}/lib

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--release --no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=--debug
PLIST_SUB+=	DEBUG=""
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/${QT_PLUGINDIR_REL}/crypto/libqca-cyrus-sasl.so

.include <bsd.port.mk>
