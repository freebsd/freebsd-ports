# New ports collection makefile for:	nzbget
# Date created:				13 April 2004
# Whom:					Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	nzbget
PORTVERSION=	0.1.1
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	nzbget

MAINTAINER=	purple@lewiz.net
COMMENT=	A binary newsreader supporting NZB files

LIB_DEPENDS=	xml2.5:${PORTSDIR}/textproc/libxml2 \
		uu.3:${PORTSDIR}/converters/uulib

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}" \
		LOCALBASE="${LOCALBASE}"
USE_GMAKE=	yes
USE_REINPLACE=	yes

PLIST_FILES=	bin/nzbget etc/nzbget.cfg.example

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/nzbget|${PREFIX}/bin/nzbget|' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/nzbget.cfg.example ${PREFIX}/etc

.include <bsd.port.mk>
