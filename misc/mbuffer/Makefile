# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mbuffer
PORTVERSION=	2018.03.18
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Tool for buffering data streams

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake localbase ssl tar:tgz
GNU_CONFIGURE=	yes
# Prevent sendfile() from being detected by configure and rejected
# by mbuffer.c due to being "unable to send from buffers".
CONFIGURE_ARGS=	ac_cv_search_sendfile=no \
		ac_cv_header_gcrypt_h=no \
		ac_cv_search_gcry_cipher_algo_name=no
MAKE_ARGS=	SHELL=/bin/sh
TEST_TARGET=	check

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
