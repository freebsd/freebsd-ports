# New ports collection makefile for: 	middleman
# Date created:		Sun Apr 27 15:48:16 CEST 2003
# Whom:                Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	middleman
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	middle-man

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A robust proxy server

WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

MAN8=		mman.8

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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
	's|/usr/bin/mman|${PREFIX}/bin/mman|g ; \
	s|/etc/mman/config.xml|${PREFIX}/etc/mman.xml|g' \
		${WRKSRC}/scripts/mman.init \
		${WRKSRC}/man/mman.8

do-install:
	@${MKDIR} ${MMAN_CACHE}
	${INSTALL_MAN} ${WRKSRC}/man/mman.8 ${MANPREFIX}/man/man8
	${INSTALL_PROGRAM} ${WRKSRC}/mman ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/config.xml \
		${PREFIX}/etc/mman.xml.dist
	${INSTALL_DATA} ${WRKSRC}/scripts/mman.init \
		${PREFIX}/etc/rc.d/mman.sh.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/scripts/filter.pl ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
