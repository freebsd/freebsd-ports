# New ports collection makefile for:	wmlj
# Date created:				6 January 2002
# Whom:				Sergei Barbarash <sgt@outline.ru>
#
# $FreeBSD$
#

PORTNAME=	wmlj
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sgt@outline.ru
COMMENT=	A dockapp that monitors your friends list at LiveJournal.com

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GNOME=	gtk12

MAN1=		wmlj.1

.include <bsd.port.mk>
