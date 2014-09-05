# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	walcommander
PORTVERSION=	0.16.1.git20140829
CATEGORIES=	x11-fm

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multi-platform open source file manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	corporateshark
GH_PROJECT=	WalCommander
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	7038a3e

USES=		cmake:outsource
USE_XORG=	x11

CMAKE_SOURCE_PATH=${WRKSRC}/wcm

PORTDOCS=	CHANGELOG CHANGELOG.GitHub README.md readme_eng.txt

PLIST_FILES=	bin/wcm \
		share/applications/wcm.desktop \
		share/pixmaps/wcm.ico

OPTIONS_DEFINE=	FREETYPE SMB SSH DOCS
OPTIONS_DEFAULT=FREETYPE SMB SSH

FREETYPE_LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
FREETYPE_CMAKE_ON=	-DWITH_FREETYPE=ON
FREETYPE_CMAKE_OFF=	-DWITH_FREETYPE=OFF
SMB_LIB_DEPENDS=	libsmbclient.so:${PORTSDIR}/net/samba-libsmbclient
SMB_CMAKE_ON=		-DWITH_SMBCLIENT=ON
SMB_CMAKE_OFF=		-DWITH_SMBCLIENT=OFF
SSH_LIB_DEPENDS=	libssh2.so:${PORTSDIR}/security/libssh2
SSH_CMAKE_ON=		-DWITH_LIBSSH2=ON
SSH_CMAKE_OFF=		-DWITH_LIBSSH2=OFF

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
