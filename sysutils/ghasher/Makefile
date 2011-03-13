# New ports collection makefile for:   ghasher
# Date Created:                        06 Dec 2005
# Whom:                                Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ghasher
PORTVERSION=	1.2.1
PORTREVISION=	5
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://asgaard.homelinux.org/code/ghasher/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI frontend to MD5 sum

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_GNOME=	gtk20 libglade2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/ghasher

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ghasher ${PREFIX}/bin

.include <bsd.port.mk>
