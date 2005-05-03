# ex:ts=8
# New ports collection makefile for:	xmlppm
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlppm
PORTVERSION=	0.98.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cs.cornell.edu/People/jcheney/xmlppm/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML-Conscious PPM Compression

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_ICONV=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexpat -liconv"

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

PLIST_FILES=	bin/xmlppm bin/xmlunppm

post-patch:
	@${REINPLACE_CMD} -e 's|^CC|#CC|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlppm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xmlunppm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
