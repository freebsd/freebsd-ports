# ex:ts=8
# New ports collection makefile for:	html2fo
# Date created:			Jul 30, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	html2fo
PORTVERSION=	0.4.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,^CC,#CC,g ; \
		s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2fo ${PREFIX}/bin

.include <bsd.port.mk>
