# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mbuffer
PORTVERSION=	2013.02.20
CATEGORIES=	misc
MASTER_SITES=	http://www.maier-komor.de/software/mbuffer/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	mm@FreeBSD.org
COMMENT=	Tool for buffering data streams

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_ARGS=	SHELL=${SH}

PLIST_FILES=	bin/mbuffer

MAN1=		${PORTNAME}.1

OPTIONS_DEFINE=	MHASH
MHASH_DESC=	Use mhash for hash generation

OPTIONS_DEFAULT=	MHASH

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMHASH}
LIB_DEPENDS+=	mhash.2:${PORTSDIR}/security/mhash
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=ac_cv_search_mhash_init=no
USE_OPENSSL=	yes
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' ${WRKSRC}/configure

.include <bsd.port.post.mk>
