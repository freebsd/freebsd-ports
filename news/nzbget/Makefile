# New ports collection makefile for:	nzbget
# Date created:				13 April 2004
# Whom:					Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	nzbget
PORTVERSION=	0.2.0
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nzbget

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	A binary newsreader supporting NZB files

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		uu.3:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}"
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes

PLIST_FILES=	bin/nzbget etc/nzbget.cfg.example

post-patch:
	@${REINPLACE_CMD} -e 's/-lpthread/${PTHREAD_LIBS}/g' ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.cfg.example ${PREFIX}/etc

.include <bsd.port.mk>
