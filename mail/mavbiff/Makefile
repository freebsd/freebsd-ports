# New ports collection makefile for:   mavbiff
# Date created:        25 December 2001
# Whom:                Edwin Groothuis (edwin@mavetju.org)
#
# $FreeBSD$
#

PORTNAME=	mavbiff
PORTVERSION=	1.1
CATEGORIES=	mail
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	edwin@mavetju.org

USE_GTK=	yes
USE_REINPLACE=	yes

MAN1=		mavbiff.1

post-patch:
	@${REINPLACE_CMD} -e "s|__GTK_CONFIG__|${GTK_CONFIG}|; \
		s|__INSTALL_DATA__|${INSTALL_DATA}|; \
		s|__INSTALL_PROG__|${INSTALL_PROGRAM}|" ${WRKSRC}/Makefile

.include <bsd.port.mk>
