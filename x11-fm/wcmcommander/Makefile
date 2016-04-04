# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wcmcommander
PORTVERSION=	0.20.0
PORTREVISION=	1
DISTVERSIONPREFIX=	release-
CATEGORIES=	x11-fm

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Multi-platform open source file manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	corporateshark
GH_PROJECT=	WCMCommander

USES=		compiler:c++11-lib cmake:outsource
CMAKE_ARGS=	-DDATADIR="${DATADIR_REL}"
USE_XORG=	x11

PORTDOCS=	CHANGELOG.txt README.md readme_eng.txt

OPTIONS_DEFINE=	FREETYPE SMB SSH DOCS
OPTIONS_DEFAULT=FREETYPE SMB SSH

FREETYPE_LIB_DEPENDS=	libfreetype.so:print/freetype2
FREETYPE_CMAKE_ON=	-DWITH_FREETYPE=ON
FREETYPE_CMAKE_OFF=	-DWITH_FREETYPE=OFF
SMB_LIB_DEPENDS=	libsmbclient.so:net/samba-libsmbclient
SMB_CMAKE_ON=		-DWITH_SMBCLIENT=ON
SMB_CMAKE_OFF=		-DWITH_SMBCLIENT=OFF
SSH_LIB_DEPENDS=	libssh2.so:security/libssh2
SSH_CMAKE_ON=		-DWITH_LIBSSH2=ON
SSH_CMAKE_OFF=		-DWITH_LIBSSH2=OFF

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == gcc
CXXFLAGS+=	-D_GLIBCXX_USE_C99 # gcc c++11 support is broken on FreeBSD
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.post.mk>
