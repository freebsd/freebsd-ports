# New ports collection Makefile for:	opentracker
# Date created:				27 July 2009
# Whom:					utisoft@gmail.com
#
# $FreeBSD$
#

PORTNAME=	opentracker
PORTVERSION=	0.2010.05.30
CATEGORIES=	net
MASTER_SITES=	http://www.bayofrum.net/dist/${PORTNAME}/ \
		http://www.glenbarber.us/ports/net/${PORTNAME}/

MAINTAINER=	utisoft@gmail.com
COMMENT=	A free lightweight bittorrent tracker using libowfat

BUILD_DEPENDS=	${LOCALBASE}/lib/libowfat.a:${PORTSDIR}/devel/libowfat

USE_BZIP2=		yes
USE_RC_SUBR=	${PORTNAME}

OPTIONS=	WANT_ACCESSLIST_BLACK "Enable client blacklisting" Off \
		WANT_ACCESSLIST_WHITE "Enable client whitelisting" Off \
		WANT_COMPRESSION_GZIP "Deliver gzip compressed full scrapes" Off \
		DEBUG_HTTPERROR "Verbose HTTPERRORs" Off \
		WANT_FULLSCRAPE "Can query tracker for all torrents" On \
		WANT_V6 "IPv6-only" Off \
		WANT_RESTRICT_STATS "Limit stats access based on IP" On

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
.if defined(WITH_WANT_RESTRICT_STATS)
FEATURES+=-DWANT_RESTRICT_STATS
.endif

MAKE_ENV+=FEATURES="${FEATURES}"

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
		${MKDIR} ${PREFIX}/etc/${PORTNAME}
		${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample \
			${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.sample

post-install:
	@if [ ! -f ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf ]; then \
		${CP} -p ${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf.sample \
			${PREFIX}/etc/${PORTNAME}/${PORTNAME}.conf ; \
		fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
