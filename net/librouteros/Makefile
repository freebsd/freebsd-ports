# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	librouteros
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://verplant.org/librouteros/files/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Library for communicating with network devices by MikroTik

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -Wno-error

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
