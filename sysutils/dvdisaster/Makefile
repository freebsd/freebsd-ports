PORTNAME=	dvdisaster
DISTVERSION=	0.79.10
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	https://dvdisaster.jcea.es/downloads/

MAINTAINER=	bob@eager.cx
COMMENT=	Optical disc error correction data and recovery tool
WWW=		https://dvdisaster.jcea.es

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash

FLAVORS=	default nox11
FLAVOR?=	${FLAVORS:[1]}
nox11_PKGNAMESUFFIX=	-nox11

USES=		gmake gnome pkgconfig tar:bz2
USE_GNOME=	glib20

HAS_CONFIGURE=	yes
CONFIGURE_LOG=	configure.log
MAKEFILE=	GNUmakefile
MAKE_JOBS_UNSAFE=	yes

CONFIGURE_ARGS=	--docsubdir="/" \
		--localedir=${PREFIX}/share/locale \
		--buildroot=${STAGEDIR} \
		--with-nls=no

SUB_FILES=	pkg-message
FLAVORS_SUB=	yes

.if ${FLAVOR} == default
LIB_DEPENDS=		libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
USE_GNOME+=		cairo gdkpixbuf2 gtk20
CONFIGURE_ARGS+=	--with-gui=yes
.endif

.if ${FLAVOR} == nox11
COMMENT+=		(without GUI)
CONFIGURE_ARGS+=	--with-gui=no
.endif

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

DOCS_CONFIGURE_ON=	--docdir=${DOCSDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/documentation/${PORTNAME}.en.1 ${STAGEDIR}${PREFIX}/share/man/man1/${PORTNAME}.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/devices.txt.in ${STAGEDIR}${DOCSDIR}/devices.txt
	${INSTALL_DATA} ${WRKSRC}/documentation/codec-specs/codecs.pdf ${STAGEDIR}${DOCSDIR}
.if ${FLAVOR} == default
	${INSTALL_DATA} ${WRKSRC}/documentation/user-manual/manual.pdf ${STAGEDIR}${DOCSDIR}/${PORTNAME}.pdf
.endif

post-install:
.if ${FLAVOR} == default
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster16.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster24.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster32.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster48.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster64.png ${STAGEDIR}${PREFIX}/share/pixmaps
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/contrib/dvdisaster.desktop ${STAGEDIR}${PREFIX}/share/applications
.endif
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
