# ex:ts=8
# Ports collection Makefile for:	kmovisto
# Date created:			Oct 23, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	kmovisto
PORTVERSION=	0.5.1
CATEGORIES=	science
MASTER_SITES=	http://mitglied.lycos.de/pageofmh/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A real 3-D molecule viewer

USE_REINPLACE=	yes
USE_QT_VER=	3
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g" \
		-e "s|-pedantic||g" ${WRKSRC}/configure

.include <bsd.port.mk>
