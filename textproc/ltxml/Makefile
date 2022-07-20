PORTNAME=	ltxml
PORTVERSION=	1.2.9
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	GENTOO \
		ftp://ftp.cogsci.ed.ac.uk/pub/LTXML/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML Toolkit

LICENSE=	GPLv2

OPTIONS_DEFINE=	OPTIMIZED_CFLAGS

WRKSRC=		${WRKDIR}/${DISTNAME}/XML

USES=		gmake perl5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-zlib=/usr --datadir=${STAGEDIR}${PREFIX}/lib/ltxml12
# textproc/py-ltxml links libltapi12.a and libltstd12.a into a shared library.
CFLAGS+=	-fPIC

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
CFLAGS+=	-Wuninitialized -ffast-math -finline-functions \
		-fomit-frame-pointer -fexpensive-optimizations -O3
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS=.*$$|CFLAGS=\$$CFLAGS|g ; \
		 s|CXXFLAGS=.*$$|CXXFLAGS=\$$CXXFLAGS|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|@prefix@|${STAGEDIR}${PREFIX}|' \
		${WRKSRC}/src/Makefile.sub.in

.include <bsd.port.mk>
