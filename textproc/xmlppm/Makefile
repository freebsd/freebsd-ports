# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlppm
PORTVERSION=	0.98.3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.cs.cornell.edu/People/jcheney/xmlppm/

MAINTAINER=	hsmtkk@gmail.com
COMMENT=	XML-Conscious PPM Compression

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		iconv gmake
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexpat ${ICONV_LIB}"
GNU_CONFIGURE=	yes

PORTDOCS=	README
PLIST_FILES=	bin/xmlppm bin/xmlunppm

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmlppm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmlunppm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
