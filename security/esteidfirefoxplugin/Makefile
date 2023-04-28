PORTNAME=	esteidfirefoxplugin
PORTVERSION=	3.8.0.1115
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://installer.id.ee/media/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Digital signing with Estonian ID card in Firefox
WWW=		https://www.id.ee/

LICENSE=	LGPL21

DEPRECATED=	Upstream last release in 2013 and has been migrated into other products of upstream
EXPIRATION_DATE=	2023-05-28
IGNORE=		Requires upstream EOL OpenSSL 1.0.X

RUN_DEPENDS=	opensc-tool:security/opensc \
		pcscd:devel/pcsc-lite

USES=		gnome pkgconfig ssl webplugin:gecko
USE_GNOME=	gtk20
WEBPLUGIN_FILES=	npesteid-firefox-plugin.so
WEBPLUGIN_DIR=	${PREFIX}/lib

ALL_TARGET=	plugin

EXTRACT_AFTER_ARGS=	--exclude 'include/openssl'

PLIST_FILES=	lib/npesteid-firefox-plugin.so

post-install:
	${INSTALL_LIB} ${WRKSRC}/npesteid-firefox-plugin.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
