# New ports collection makefile for:	fsh
# Date created:				Thu Jan 24 03:37:54 JST 2002
# Whom:					sumikawa
#
# $FreeBSD$

PORTNAME=	fsh
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.lysator.liu.se/fsh/

MAINTAINER=	sumikawa@FreeBSD.org
COMMENT=	Fast remote command execution

USE_PYTHON=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

post-patch:
	${REINPLACE_CMD} -e '/^[^#]/s/FCNTL/fcntl/g' ${WRKSRC}/fshcompat.py

.include <bsd.port.mk>
