# New ports collection makefile for:	playd
# Date created:				Apr 29, 2009
# Whom:					Aldis Berjoza <killasmurf86@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playd
PORTVERSION=	1.7.12
CATEGORIES=	multimedia
MASTER_SITES=	http://files.bsdroot.lv/FreeBSD/distfiles/
DISTNAME=	playd.sh-${PORTVERSION}

MAINTAINER=	aldis@bsdroot.lv
COMMENT=	Very easy to use mplayer sh wrapper script (supports playlists)

RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer

LICENSE=	BSD

CONFLICTS=	playd2-2.[0-9]*
PLIST_FILES=	bin/playd
MAN1=		playd.1

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/playd.sh ${PREFIX}/bin/playd
	${INSTALL_MAN} ${WRKSRC}/man/man1/playd.1 ${PREFIX}/man/man1/

.include <bsd.port.mk>
