# New ports collection makefile for:	qca-ossl
# Date created:				2008-07-13
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	qca-ossl
DISTVERSION=	2.0.0-beta3
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/plugins/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	QCA OpenSLL plugin

LIB_DEPENDS=	qca.2:${PORTSDIR}/devel/qca

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
USE_OPENSSL=	yes

CONFIGURE_ARGS=	--plugins-path=${PREFIX}/${QT_PLUGINDIR_REL} \
		--with-openssl-inc=${OPENSSLINC} \
		--with-openssl-lib=${OPENSSLLIB}

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--release --no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=--debug
PLIST_SUB+=	DEBUG=""
.endif

post-install:
	${STRIP_CMD} ${PREFIX}/${QT_PLUGINDIR_REL}/crypto/libqca-ossl.so

.include <bsd.port.mk>
