# Created by: Mark Felder <feld@freebsd.org>
# $FreeBSD$

PORTNAME=	librouteros
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://verplant.org/librouteros/files/

MAINTAINER=	feld@freebsd.org
COMMENT=	Library for communicating with network devices by MikroTik

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt

MAN1=		ros.1
MAN3=		librouteros.3

USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include -Wno-error

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
