# ex:ts=8
# New ports collection makefile for:	liboe
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	liboe
PORTVERSION=	0.92
CATEGORIES=	mail
MASTER_SITES=	http://www.gpl.no/liboe/download/

MAINTAINER=	ijliao@FreeBSD.org

USE_REINPLACE=	yes
MAKEFILE=	makefile
ALL_TARGET=	clean oe2mbx liboe
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^PREFIX,#PREFIX,g ; \
		s,gcc,${CC} ${CFLAGS},g" ${WRKSRC}/${MAKEFILE}

.include <bsd.port.mk>
