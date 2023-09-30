PORTNAME=	source-highlight
DISTVERSION=	3.1.9
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	GNU/src-highlite

MAINTAINER=	tcberner@FreeBSD.org
COMMENT=	C/C++ and Java sources to HTML converter
WWW=		https://www.gnu.org/software/src-highlite/source-highlight.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	exctags:devel/ctags
LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		compiler:c++11-lang gmake pathfix libtool localbase
USE_CXXSTD=	gnu++11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bash-completion
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	java2html # bin/java2html

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*
INFO=		source-highlight-lib source-highlight

do-test:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${_MAKE_JOBS} ${MAKE_ARGS} check

.include <bsd.port.mk>
