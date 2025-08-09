PORTNAME=	arataga
PORTVERSION=	0.5.4
DISTVERSIONPREFIX=	v
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/sobjectizer/oess/oess-2:oess
DISTFILES=	oess-2.2.3-full.tar.bz2:oess

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Performant SOCKS5/HTTP1.1 proxy server
WWW=		https://github.com/Stiffstream/arataga

LICENSE=	AGPLv3

BUILD_DEPENDS=	${LOCALBASE}/include/spdlog/spdlog.h:devel/spdlog \
		${LOCALBASE}/include/asio/ip/address.hpp:net/asio \
		${LOCALBASE}/include/args.hxx:devel/args
LIB_DEPENDS=	libso.${_SO5_LIBVER}.so:devel/sobjectizer \
		libfmt.so:devel/libfmt \
		libhttp_parser.so:www/http-parser
TEST_DEPENDS=	${LOCALBASE}/include/doctest/doctest.h:devel/doctest

USES=		compiler:c++17-lang gmake
MAKEFILE=	${FILESDIR}/makefile
MAKE_ENV=	SO5_LIBVER=${_SO5_LIBVER}
WRKSRC_SUBDIR=	${PORTNAME}

TEST_TARGET=	run_unit_tests
TEST_WRKSRC=	${WRKSRC}/../tests

USE_GITHUB=	yes
GH_ACCOUNT=	Stiffstream
GH_PROJECT=	noexcept-ctcheck:nectc restinio:rinio so5extra:so5e
GH_TAGNAME=	v.1.0.0:nectc v.0.6.16:rinio v.1.6.2:so5e

_SO5_LIBVER=	5.8.3

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*.md

OPTIONS_DEFINE=	DOCS

post-extract:
	@${LN} -s ../../noexcept-ctcheck-v.1.0.0/noexcept_ctcheck \
		../../restinio-v.0.6.16/dev/restinio \
		../../so5extra-v.1.6.2/dev/so_5_extra \
		../../oess-2.2.3/dev/cpp_util_2 \
		../../oess-2.2.3/dev/oess_2 ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e '/^#include </s,nodejs/http_parser/,,' \
		${WRKSRC}/acl_handler/handlers/http/basics.hpp \
		${WRKSRC}/acl_handler/handlers/http/helpers.hpp
	@${REINPLACE_CMD} -e '/#include/s,args/,,' ${WRKSRC}/main.cpp

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
