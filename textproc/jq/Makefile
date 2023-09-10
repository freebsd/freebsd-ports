PORTNAME=	jq
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Lightweight and flexible command-line JSON processor
WWW=		https://stedolan.github.io/jq/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf bison cpe gmake libtool
USE_CSTD=	gnu99
USE_LDCONFIG=	yes

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	stedolan

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--docdir="${DOCSDIR}" \
		--disable-maintainer-mode

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # 3 tests fail, see https://github.com/jqlang/jq/issues/2885

PORTDOCS=	*

OPTIONS_DEFINE=			DOCS ONIGURUMA
OPTIONS_DEFAULT=		ONIGURUMA

DOCS_MAKE_ARGS_OFF=		docdir=
DOCS_CONFIGURE_ENABLE=		docs

ONIGURUMA_DESC=			With oniguruma BSDL regular expression library
ONIGURUMA_LIB_DEPENDS=		libonig.so:devel/oniguruma
ONIGURUMA_CONFIGURE_WITH=	oniguruma=${LOCALBASE}

.include <bsd.port.mk>
