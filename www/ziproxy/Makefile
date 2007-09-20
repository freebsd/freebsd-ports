# New ports collection makefile for:	ziproxy
# Date created:				2006-07-28
# Whom:					Pankov Pavel <pankov_p@mail.ru>
#
# $FreeBSD$

PORTNAME=		ziproxy
PORTVERSION=		2.3.0
CATEGORIES=		www
MASTER_SITES=		SF

MAINTAINER=		pankov_p@mail.ru
COMMENT=		A forwarding, non-caching, compressing proxy server

LIB_DEPENDS=		ungif.5:${PORTSDIR}/graphics/libungif \
			png.5:${PORTSDIR}/graphics/png \
			jpeg.9:${PORTSDIR}/graphics/jpeg \
			confuse.0:${PORTSDIR}/devel/libconfuse

USE_BZIP2=		yes
USE_GCC=		3.2+

CFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
ERRORFILES=		400.html 404.html 408.html 500.html 503.html

CONFIGURE_ENV+=		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-shared-confuse --with-cfgfile="${PREFIX}/etc/ziproxy.conf"

.if !defined(NOPORTDOCS)
PORTDOCS=		README
.endif

USE_RC_SUBR=		ziproxy

SUB_FILES+=		pkg-message

OPTIONS+=		JPEG2000 "Build with JPEG2000 support" on

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	                  -e 's|%%DATADIR%%|${DATADIR}|g' \
		${WRKSRC}/etc/ziproxy.conf

	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-install:
	@${MKDIR} ${PREFIX}/etc
	@${INSTALL_DATA} ${WRKSRC}/etc/ziproxy.conf ${PREFIX}/etc/ziproxy.conf.sample
	@if [ ! -f ${PREFIX}/etc/ziproxy.conf ]; then \
		${CP} -p ${WRKSRC}/etc/ziproxy.conf ${PREFIX}/etc/ziproxy.conf ; \
	fi

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}/${DOC}
.endfor
.endif

	@${MKDIR} ${DATADIR}/error
.for FILE in ${ERRORFILES}
	@${INSTALL_DATA} ${WRKSRC}/var/ziproxy/error/${FILE} ${DATADIR}/error/${FILE}
.endfor

	@${INSTALL_SCRIPT} ${WRKSRC}/src/tools/ziproxy_genhtml_stats.sh ${PREFIX}/bin

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_JPEG2000)
CONFIGURE_ARGS+=	--without-jasper
.else
CONFIGURE_ARGS+=	--with-jasper
LIB_DEPENDS+=		jasper.4:${PORTSDIR}/graphics/jasper
.endif

.include <bsd.port.post.mk>
