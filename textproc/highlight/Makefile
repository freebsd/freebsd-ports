# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	highlight
PORTVERSION=	3.28
PORTEPOCH=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.andre-simon.de/zip/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Customizable syntax highlighter

BUILD_DEPENDS=	boost-libs>0:devel/boost-libs

USES=		dos2unix gmake lua:52 pkgconfig tar:bzip2
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

.include <bsd.port.mk>
