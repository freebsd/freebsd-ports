# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	highlight
PORTVERSION=	3.60
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
	@cd ${STAGEDIR}${PREFIX}/etc/highlight && ${MV} filetypes.conf \
		filetypes.conf.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/highlight

.include <bsd.port.mk>
