# New ports collection makefile for:	nzbget
# Date created:				13 April 2004
# Whom:					Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	nzbget
PORTVERSION=	0.2.3
CATEGORIES=	news
MASTER_SITES=	SF

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	A binary newsreader supporting NZB files

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		uu.3:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}"
USE_GMAKE=	yes

PLIST_FILES=	bin/nzbget etc/nzbget.cfg.example

post-extract:
	@${LN} -sf ${WRKSRC}/uulib/uudeview.h ${WRKSRC}/uudeview.h

post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '187s/int/intptr_t/' ${WRKSRC}/ArticleDownloader.cpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.cfg.example ${PREFIX}/etc

.include <bsd.port.mk>
