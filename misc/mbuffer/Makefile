# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mbuffer
PORTVERSION=	2017.10.11
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tool for buffering data streams

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase ssl tar:tgz
GNU_CONFIGURE=	yes
# Prevent sendfile() from being detected by configure and rejected
# by mbuffer.c due to being "unable to send from buffers".
CONFIGURE_ARGS=	ac_cv_search_sendfile=no
MAKE_ARGS=	SHELL=/bin/sh

OPTIONS_DEFINE=	MHASH
OPTIONS_DEFAULT=	MHASH

MHASH_DESC=	Use mhash for hash generation

MHASH_LIB_DEPENDS=	libmhash.so:security/mhash
MHASH_CONFIGURE_OFF=	ac_cv_search_mhash_init=no

post-configure:
	# Rename variables to make sure they aren't redefined through mhash.h
	@${REINPLACE_CMD} -E -e 's@(PACKAGE|VERSION)@MBUFFER_\1@' \
		${WRKSRC}/config.h ${WRKSRC}/settings.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/mbuffer
	${MV} ${STAGEDIR}${PREFIX}/etc/mbuffer.rc \
		${STAGEDIR}${PREFIX}/etc/mbuffer.rc.sample

.include <bsd.port.mk>
