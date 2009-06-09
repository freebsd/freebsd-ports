# New ports collection makefile for:	playd
# Date created:				Apr 29, 2009
# Whom:					Aldis Berjoza <killasmurf86@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playd
PORTVERSION=	1.1.5
CATEGORIES=	multimedia
MASTER_SITES=	http://www.logvinov.ru/files/dist/playd/

MAINTAINER=	killasmurf86@gmail.com
COMMENT=	Very easy to use mplayer sh wrapper script, with usefull features

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

PLIST_FILES=	bin/playd

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/playd ${PREFIX}/bin/playd

.include <bsd.port.mk>
