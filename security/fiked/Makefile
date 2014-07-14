# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	fiked
PORTVERSION=	0.0.5
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/dist/fiked/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake IKE PSK+XAUTH daemon based on VPNC

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

USES=	tar:bzip2 gmake

OPTIONS_DEFINE=	LIBNET DOCS
OPTIONS_DEFAULT=LIBNET
LIBNET_DESC=	Build with libnet support

LIBNET_LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/fiked man/man1/fiked.1.gz
PORTDOCS=	README NEWS

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -e 's|=-g|=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiked ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fiked.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
