# ex:ts=8
# New ports collection makefile for:	xmlppm
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xmlppm
PORTVERSION=	0.97
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.cs.cornell.edu/People/jcheney/xmlppm/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XML-Conscious PPM Compression

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		expat.4:${PORTSDIR}/textproc/expat2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

USE_GMAKE=	yes
MAKE_ARGS=	CC="${CXX}" OPT_FLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lexpat -liconv"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmlppm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xmlunppm ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${DOCSDIR}
.endif

.include <bsd.port.mk>
