# New ports collection makefile for:	c-nocem
# Date created:		19.May 1999
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.6
CATEGORIES=	news security
MASTER_SITES=	http://sites.inka.de/~bigred/sw/ \
		ftp://ftp.lan-ks.de/pub/FreeBSD/distfiles/

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${WRKDIRPREFIX}${PORTSDIR}/news/cnews/work/conf/substitutions:${PORTSDIR}/news/cnews:configure

WRKSRC=		${WRKDIR}/c-nocem
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${WRKDIRPREFIX}/${PORTSDIR}/news/cnews/work

.include <bsd.port.mk>
