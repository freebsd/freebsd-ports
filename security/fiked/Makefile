# New ports collection makefile for:	fiked
# Date created:				2005-12-07
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	fiked
PORTVERSION=	0.0.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	http://dragon.roe.ch/bitsnpieces/fiked/ \
		http://mirror.roe.ch/dist/fiked/

MAINTAINER=	daniel@roe.ch
COMMENT=	A fake IKE PSK+XAUTH daemon based on VPNC

LIB_DEPENDS=	gcrypt.15:${PORTSDIR}/security/libgcrypt
.if !defined(WITHOUT_LIBNET)
BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/fiked
MAN1=		fiked.1
PORTDOCS=	README NEWS

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e \
		's|=-g|=|; \
		 s|-lnet|`${LIBNET_CONFIG} --libs`|; \
		 s|-DWITH_LIBNET|& `${LIBNET_CONFIG} --cflags`|' \
		${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiked ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fiked.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
