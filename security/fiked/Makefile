# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	fiked
PORTVERSION=	0.0.5
PORTREVISION=	7
CATEGORIES=	security
MASTER_SITES=	http://mirror.roe.ch/dist/fiked/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fake IKE PSK+XAUTH daemon based on VPNC

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		gmake tar:bzip2

MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/fiked man/man1/fiked.1.gz
PORTDOCS=	README NEWS

OPTIONS_DEFINE=	LIBNET DOCS
OPTIONS_DEFAULT=LIBNET
LIBNET_DESC=	Build with libnet support
LIBNET_LIB_DEPENDS=	libnet.so:net/libnet

post-patch:
	@${REINPLACE_CMD} -e 's|=-g|=|' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fiked ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fiked.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
