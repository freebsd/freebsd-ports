# New ports collection makefile for:	fiked
# Date created:				2005-12-07
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	fiked
PORTVERSION=	0.0.4
CATEGORIES=	security
MASTER_SITES=	http://dragon.roe.ch/bitsnpieces/fiked/ \
		http://home.tiscalinet.ch/roe/fiked/

MAINTAINER=	daniel@roe.ch
COMMENT=	A fake IKE PSK+XAUTH daemon based on VPNC

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt
.if !defined(WITHOUT_LIBNET)
BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GCC=	3.2+

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/fiked
MAN1=		fiked.1
PORTDOCS=	README NEWS

post-patch:
	@${REINPLACE_CMD} -e 's|=-g|=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiked ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fiked.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
