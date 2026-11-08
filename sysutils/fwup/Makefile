PORTNAME=	fwup
DISTVERSION=	1.17.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/fwup-home/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurable embedded Linux firmware update creator and runner
WWW=		https://github.com/fhunleth/fwup

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	help2man:misc/help2man
LIB_DEPENDS=	libconfuse.so:devel/libconfuse
#TEST_DEPENDS=	mdir:filesystems/mtools

USES=		gettext-runtime libarchive libtool pkgconfig

GNU_CONFIGURE=	yes

EXTRACT_AFTER_ARGS=	--exclude scripts \
			--no-same-owner --no-same-permissions

PLIST_FILES=	bin/fwup \
		bin/img2fwup \
		share/bash-completion/completions/fwup \
		share/man/man1/fwup.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
