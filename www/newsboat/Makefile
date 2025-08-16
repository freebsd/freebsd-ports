PORTNAME=	newsboat
DISTVERSION=	2.40
CATEGORIES=	www
MASTER_SITES=	https://newsboat.org/releases/${DISTVERSION}/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mt-bugs@markoturk.info
COMMENT=	RSS feed reader for the text console
WWW=		https://newsboat.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	asciidoctor:textproc/rubygem-asciidoctor
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libjson-c.so:devel/json-c \
		libstfl.so:devel/stfl

USES=		cargo compiler:c++11-lang gettext gmake gnome iconv:translit \
		ncurses pkgconfig python:env shebangfix sqlite ssl tar:xz
USE_GNOME=	libxml2

SHEBANG_FILES=	contrib/bookmark-evernote.sh contrib/exportOPMLWithTags.py \
		contrib/feedgrabber.rb contrib/getpocket.com/send-to-pocket.sh \
		contrib/heise.rb contrib/image-pager/bootstrap_image_pager.sh \
		contrib/image-preview/nbparser contrib/move_url.py \
		contrib/newsboat_reorganize.py contrib/slashdot.rb \
		doc/examples/example-exec-script.py

CARGO_BUILD=		no
CARGO_INSTALL=		no
CARGO_TARGET_DIR=	${WRKSRC}/target

MAKE_ENV=	${CARGO_ENV}

TESTING_UNSAFE=	tests fail if run as root

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,fail "ncursesw",true,; s,fail "libcrypto",true,' \
		-e 's,fail "libssl",true,' \
		${WRKSRC}/config.sh
	@${REINPLACE_CMD} -e 's|-liconv|${ICONV_LIB} -lcrypto ${NCURSESLIBS}|;s|-Werror||' \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
