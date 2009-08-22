# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	links
PORTVERSION=	0.98
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~mikulas/vyplody/links/download/ \
		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}		


MAINTAINER=	demon@FreeBSD.org
COMMENT=	Lynx-like text WWW browser

GNU_CONFIGURE=	yes

USE_OPENSSL=	yes
NO_LATEST_LINK=	yes
CONFLICTS=	links-2*

MAN1=		links.1

.include <bsd.port.mk>
