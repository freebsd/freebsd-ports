# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	fiked
PORTVERSION=	0.0.5
PORTREVISION=	4
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/dist/fiked/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake IKE PSK+XAUTH daemon based on VPNC

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt
.if !defined(WITHOUT_LIBNET)
LIB_DEPENDS+=	net:${PORTSDIR}/net/libnet
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/fiked
MAN1=		fiked.1
PORTDOCS=	README NEWS

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

NO_STAGE=	yes
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
