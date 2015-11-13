# $FreeBSD$

PORTNAME=	htmlcxx
PORTVERSION=	0.85
PORTREVISION=	2
CATEGORIES=	www textproc
MASTER_SITES=	SF

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	HTML and CSS APIs for C++

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/LGPL_V2

USES=		bison iconv libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

MAKE_JOBS_UNSAFE=yes

MAKE_ARGS=	pkgconfigdir="${PREFIX}/libdata/pkgconfig"

.include <bsd.port.pre.mk>

.if !empty(ICONV_LIB)
CONFIGURE_ARGS+=ac_cv_lib_iconv_iconv_open=yes
.endif

post-patch:
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

.include <bsd.port.post.mk>
