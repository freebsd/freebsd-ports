# New ports collection Makefile for:	opentracker
# Date created:				27 July 2009
# Whom:					utisoft@gmail.com
#
# $FreeBSD$
#

PORTNAME=	opentracker
PORTVERSION=	0.2009.06.27
CATEGORIES=		net
MASTER_SITES=	http://www.bayofrum.net/opentracker/ \
		http://freebsd.dev-urandom.com/opentracker/

MAINTAINER=	utisoft@gmail.com
COMMENT=	A free lightweight bittorrent tracker using libowfat

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/devel/libowfat

USE_RC_SUBR=	opentracker

OPTIONS=WANT_ACCESSLIST_BLACK "Enable client blacklisting" Off \
	WANT_ACCESSLIST_WHITE "Enable client whitelisting" Off \
	WANT_COMPRESSION_GZIP "Deliver gzip compressed full scrapes" Off \
	DEBUG_HTTPERROR "Verbose HTTPERRORs" Off \
	WANT_FULLSCRAPE "Can query tracker for all torrents" On \
	WANT_V6 "IPv6-only" Off \

.include <bsd.port.options.mk>

.if defined(WITH_WANT_ACCESSLIST_BLACK)
FEATURES+=-DWANT_ACCESSLIST_BLACK
.endif
.if defined(WITH_WANT_ACCESSLIST_WHITE)
FEATURES+=-DWANT_ACCESSLIST_WHITE
.endif
.if defined(WITH_WANT_COMPRESSION_GZIP)
FEATURES+=-DWANT_COMPRESSION_GZIP
.endif
.if defined(WITH_DEBUG_HTTPERROR)
FEATURES+=-D_DEBUG_HTTPERROR
.endif
.if defined(WITH_WANT_FULLSCRAPE)
FEATURES+=-DWANT_FULLSCRAPE
.endif
.if defined(WITH_WANT_V6)
FEATURES+=-DWANT_V6
.endif

MAKE_ENV+=FEATURES="${FEATURES}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
		${MKDIR} ${PREFIX}/etc/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.sample \
			${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf ; \
		fi

.include <bsd.port.mk>
