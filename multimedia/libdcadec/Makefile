# $FreeBSD$

PORTNAME=	libdcadec
PORTVERSION=	0.2.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	multimedia

MAINTAINER=	mickael.maillot@gmail.com
COMMENT=	DTS Coherent Acoustics decoder with support for HD extensions

LICENSE=	LGPL21

USE_GITHUB=	yes
GH_ACCOUNT=	foo86
GH_PROJECT=	dcadec

USES=		pkgconfig gmake
LDFLAGS+=	-lm
MAKE_ENV+=	CONFIG_SHARED=yes

USE_LDCONFIG=	yes

post-patch:
	${REINPLACE_CMD} -e 's;INCLUDEDIR;MYINCLUDEDIR;g' \
		-e 's;$$(LIBDIR)/pkgconfig;$$(PREFIX)/libdata/pkgconfig;' \
		-e 's;LIBDIR;MYLIBDIR;g' \
		${WRKSRC}/dcadec.pc.in \
		${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dcadec
	${MV} ${STAGEDIR}${PREFIX}/bin/dcadec ${STAGEDIR}${PREFIX}/bin/libdcadec
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${PORTNAME}.so.0.1.0

.include <bsd.port.mk>
