# New ports collection makefile for: 	middleman
# Date created:		Sun Apr 27 15:48:16 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	middleman
PORTVERSION=	1.6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	middle-man
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ponomarew@oberon.net
COMMENT=	Middleman is a robust proxy server

WRKSRC=		${WRKDIR}/middleman

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

.if defined(WITH_SYSLOG)
CONFIGURE_ARGS+=	--enable-syslog
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_MTIME)
CONFIGURE_ARGS+=	--enable-mtime
.endif

MMAN_CACHE=	/var/cache/mman
PLIST_SUB+=	MMAN_CACHE=${MMAN_CACHE}

post-patch:
	@${REINPLACE_CMD} -e \
	's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
	's|/usr/bin/mman|${PREFIX}/bin/mman|g ; \
	s|/etc/mman/config.xml|${PREFIX}/etc/mman.xml|g' \
		${WRKSRC}/scripts/mman.init

do-install:
	@${MKDIR} ${MMAN_CACHE}
	${INSTALL_PROGRAM} ${WRKSRC}/mman ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config.xml \
		${PREFIX}/etc/mman.xml
	${INSTALL_DATA} ${WRKSRC}/scripts/mman.init \
		${PREFIX}/etc/rc.d/mman.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/middleman
	${INSTALL_DATA} ${WRKSRC}/scripts/filter.pl \
		${PREFIX}/share/doc/middleman/
	${INSTALL_DATA} ${WRKSRC}/README.html \
		${PREFIX}/share/doc/middleman/
.endif

.include <bsd.port.mk>
