# New ports collection makefile for:	c-nocem
# Date created:		19.May 1999
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.6
CATEGORIES=	news security
MASTER_SITES=	http://sites.inka.de/~bigred/sw/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dirk.meyer@dinoex.sub.org

BUILD_DEPENDS=	${WRKDIRPREFIX}${CNEWSSRC}/conf/substitutions:${PORTSDIR}/news/cnews:configure \
		gpg:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/c-nocem
CNEWSSRC?=	${.CURDIR}/../cnews/work
NEWSBIN?=	${PREFIX}/news/cnewsbin
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${WRKDIRPREFIX}${CNEWSSRC}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}

.include <bsd.port.mk>
