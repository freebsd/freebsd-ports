# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mbuffer
PORTVERSION=	2015.10.02
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tool for buffering data streams

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake tar:tgz
GNU_CONFIGURE=	yes
MAKE_ARGS=	SHELL=${SH}

PLIST_FILES=	bin/mbuffer man/man1/mbuffer.1.gz

OPTIONS_DEFINE=	MHASH
MHASH_DESC=	Use mhash for hash generation

OPTIONS_DEFAULT=	MHASH

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMHASH}
LIB_DEPENDS+=	libmhash.so:security/mhash
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=ac_cv_search_mhash_init=no
USE_OPENSSL=	yes
.endif

# Prevent sendfile() from being detected by configure and rejected
# by mbuffer.c due to being "unable to send from buffers".
CONFIGURE_ARGS+=ac_cv_search_sendfile=no

.include <bsd.port.pre.mk>

post-configure:
	# Rename variables to make sure they aren't redefined through mhash.h
	@${REINPLACE_CMD} -E -e 's@(PACKAGE|VERSION)@MBUFFER_\1@' \
		${WRKSRC}/config.h ${WRKSRC}/mbuffer.c

.include <bsd.port.post.mk>
