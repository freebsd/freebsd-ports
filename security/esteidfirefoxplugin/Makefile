# $FreeBSD$

PORTNAME=	esteidfirefoxplugin
PORTVERSION=	3.8.0.1115
CATEGORIES=	security
MASTER_SITES=	https://installer.id.ee/media/sources/

MAINTAINER=	toomas.aas@raad.tartu.ee
COMMENT=	Digital signing with Estonian ID card in Firefox

LICENSE=	LGPL21

RUN_DEPENDS=	opensc-tool:security/opensc \
		pcscd:devel/pcsc-lite

USE_OPENSSL=	yes
USE_GNOME=	gtk20
USES=		webplugin:gecko pkgconfig
WEBPLUGIN_DIR=	${PREFIX}/lib
WEBPLUGIN_FILES=	npesteid-firefox-plugin.so

ALL_TARGET=	plugin

EXTRACT_AFTER_ARGS=	--exclude 'include/openssl'

PLIST_FILES=	lib/npesteid-firefox-plugin.so

post-install:
	${INSTALL_LIB} ${WRKSRC}/npesteid-firefox-plugin.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
