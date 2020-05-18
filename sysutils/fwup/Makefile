# $FreeBSD$

PORTNAME=	fwup
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0
CATEGORIES=	sysutils

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Configurable embedded Linux firmware update creator and runner

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/bin/autogen:devel/autogen \
		${LOCALBASE}/bin/base64:converters/base64 \
		${LOCALBASE}/bin/help2man:misc/help2man \
		${LOCALBASE}/bin/mdir:emulators/mtools \
		${LOCALBASE}/bin/zip:archivers/zip
LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libsodium.so:security/libsodium

USES=		autoreconf libarchive libtool pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	fhunleth

GNU_CONFIGURE=	yes

SHEBANG_FILES=	img2fwup scripts/*.sh

PLIST_FILES=	bin/fwup \
		bin/img2fwup \
		man/man1/fwup.1.gz \
		share/bash-completion/completions/fwup

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
