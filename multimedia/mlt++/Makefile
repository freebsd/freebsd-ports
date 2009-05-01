# New ports collection makefile for:	mlt++
# Date created:				14 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	mlt++
PORTVERSION=	0.3.8
CATEGORIES=	multimedia
MASTER_SITES=	SFE
MASTER_SITE_SUBDIR=	mlt

MAINTAINER=	villa.alberto@gmail.com
COMMENT=	C++ wrapping for the MLT library

LIB_DEPENDS=	mlt.1:${PORTSDIR}/multimedia/mlt

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog COPYING \
		CUSTOMISING HOWTO README

pre-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure \
		${WRKSRC}/swig/*/build

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
