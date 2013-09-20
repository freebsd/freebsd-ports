# Created by: ijliao
# $FreeBSD$

PORTNAME=	xmlppm
PORTVERSION=	0.98.3
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION} \
		http://www.cs.cornell.edu/People/jcheney/xmlppm/


MAINTAINER=	hsmtkk@gmail.com
COMMENT=	XML-Conscious PPM Compression

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2

USES=		iconv
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexpat ${ICONV_LIB}"
GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

PLIST_FILES=	bin/xmlppm bin/xmlunppm

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmlppm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xmlunppm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
