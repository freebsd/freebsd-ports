# New ports collection makefile for:	wmlj
# Date created:				6 January 2002
# Whom:				Sergei Barbarash <sgt@outline.ru>
#
# $FreeBSD$
#

PORTNAME=	wmlj
PORTVERSION=	0.2
CATEGORIES=	net
MASTER_SITES=	http://telia.dl.sourceforge.net/wmlj/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sgt@outline.ru

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
USE_GTK=	yes

MAN1=		wmlj.1

.include <bsd.port.mk>
