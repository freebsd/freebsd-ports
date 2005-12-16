# New ports collection makefile for:	fiked
# Date created:				2005-12-07
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	fiked
PORTVERSION=	0.0.2
CATEGORIES=	security
MASTER_SITES=	http://dragon.roe.ch/bitsnpieces/fiked/ \
		http://home.tiscalinet.ch/roe/fiked/

MAINTAINER=	daniel@roe.ch
COMMENT=	A fake IKE PSK+XAUTH daemon based on VPNC

LIB_DEPENDS=	gcrypt.13:${PORTSDIR}/security/libgcrypt
BUILD_DEPENDS=	libnet*>=1.1.2,1:${PORTSDIR}/net/libnet

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

MAKEFILE=	GNUmakefile

MAKE_ENV+=	CC="${CC}"

PLIST_FILES=	bin/fiked
MAN1=		fiked.1
PORTDOCS=	README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^\(CC\)=|\1?=|; s|=-g|=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiked ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fiked.1 ${PREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
