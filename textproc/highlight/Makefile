# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

# 3.29+ needs to_string() which gcc48 (for 9.3-R) doesn't provide
PORTNAME=	highlight
PORTVERSION=	3.29
PORTREVISION=	1
PORTEPOCH=	3
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Customizable syntax highlighter

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		compiler:c++11-lib dos2unix gmake lua:52 pkgconfig tar:bzip2
USE_CXXSTD=	c++11
MAKEFILE=	makefile
MAKE_ARGS=	CXX="${CXX}" \
		CFLAGS="${CXXFLAGS} ${CPPFLAGS} -DHAVE_DECL_GETOPT" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} \
		-e 's|^PREFIX =|PREFIX ?=|' \
		-e 's|^conf_dir =.*|conf_dir = $${PREFIX}/etc/highlight/|' \
		${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|^CXX=|CXX?=|' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/src/${MAKEFILE}

post-install:
	@cd ${STAGEDIR}${PREFIX}/etc/highlight && ${MV} filetypes.conf \
		filetypes.conf.sample
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/highlight

.include <bsd.port.mk>
