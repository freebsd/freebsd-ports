# Created by: ijliao
# $FreeBSD$

PORTNAME=	hydra
PORTVERSION=	0.1.8
PORTREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://hydra.hellug.gr/download/
PKGNAMESUFFIX=	-web

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High performance multi-threaded web server

LIB_DEPENDS=	libgnutls.so:security/gnutls

BROKEN=		Needs to be ported to GnuTLS 3.4; abandoned upstream

USES=		perl5 pkgconfig shebangfix
SHEBANG_FILES=	src/webindex.pl
USE_RC_SUBR=	hydra
USE_PERL5=	run
GNU_CONFIGURE=	yes

CFLAGS+=	-DENABLE_SSL -DHAVE_LIBGNUTLS
CPPFLAGS+=	$$(pkg-config --cflags gnutls)
LDFLAGS+=	$$(pkg-config --libs gnutls)

PLIST_SUB=	LOGDIR="${LOGDIR}"

SUB_FILES=	pkg-deinstall
SUB_LIST=	LOGDIR="${LOGDIR}"

CONFLICTS_INSTALL=	hydra-[0-9]*

LOGDIR?=	/var/log/hydra

post-patch:
	@${REINPLACE_CMD} -e \
		'/LDFLAGS/s| -g"|"|' ${WRKSRC}/configure
.for f in src/defines.h examples/hydra.conf
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g ; \
		 s|%%LOGDIR%%|${LOGDIR}|g ; \
		 s|%%WWWOWN%%|${WWWOWN}|g ; \
		 s|%%WWWGRP%%|${WWWGRP}|g' ${WRKSRC}/${f}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${LOGDIR}
.for f in hydra.conf mime.types
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} ${f} \
		${STAGEDIR}${ETCDIR}/${f}.sample)
.endfor

.include <bsd.port.mk>
