# Created by: Adam Weinberger <adamw@FreeBSD.org>

PORTNAME=	highlight
PORTVERSION=	4.0
PORTEPOCH=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Customizable syntax highlighter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		compiler:c++11-lib gmake lua pkgconfig tar:bzip2
USE_CXXSTD=	c++11
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install:
.for cfg in filetypes lsp
	@cd ${STAGEDIR}${ETCDIR} && ${MV} ${cfg}.conf ${cfg}.conf.sample
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/highlight

.include <bsd.port.mk>
