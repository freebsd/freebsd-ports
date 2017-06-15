# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	middleman
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/middle-man/Source/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Robust proxy server

OPTIONS_DEFINE=	SYSLOG DEBUG MTIME DOCS

SYSLOG_DESC=	Enable syslog support
MTIME_DESC=	Enable mtime support

SYSLOG_CONFIGURE_ON=	--enable-syslog
DEBUG_CONFIGURE_ON=	--enable-debug
MTIME_CONFIGURE_ON=	--enable-mtime

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
USES=		gmake

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -pthread

MAKE_JOBS_UNSAFE=	yes

MMAN_CACHE=	/var/cache/mman
PLIST_SUB+=	MMAN_CACHE=${MMAN_CACHE}

post-patch:
	@${REINPLACE_CMD} -e \
	's|/usr/bin/mman|${PREFIX}/bin/mman|g ; \
	s|/etc/mman/config.xml|${PREFIX}/etc/mman.xml|g' \
		${WRKSRC}/scripts/mman.init \
		${WRKSRC}/man/mman.8

do-install:
	@${MKDIR} ${STAGEDIR}${MMAN_CACHE}
	${INSTALL_MAN} ${WRKSRC}/man/mman.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/mman ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config.xml \
		${STAGEDIR}${PREFIX}/etc/mman.xml.sample
	${INSTALL_DATA} ${WRKSRC}/scripts/mman.init \
		${STAGEDIR}${PREFIX}/etc/rc.d/mman.sh.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/filter.pl ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
