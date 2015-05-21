# Created by: Frank Laszlo <laszlof@vonostingroup.com>
# $FreeBSD$

PORTNAME=	ncrypt
PORTVERSION=	0.8.0
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION:R}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Advanced AES file encryption tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf tar:tgz
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/ncrypt bin/nrm

pre-patch:
	@${RM} ${WRKSRC}/*.m4

post-patch:
	@${REINPLACE_CMD} -e \
		's| getopt.c getopt1.c||' ${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e \
		's|-O0|| ; \
		 s|"\($$CCOPTS\)"|"\1 $$CFLAGS"|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
