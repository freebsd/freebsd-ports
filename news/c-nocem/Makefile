# New ports collection makefile for:	c-nocem
# Date created:		19.May 1999
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$

PORTNAME=	c-nocem
PORTVERSION=	3.7
PORTREVISION=	1
CATEGORIES=	news security
MASTER_SITES=	http://sites.inka.de/~bigred/sw/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	NoCeM for C News and INN

BUILD_DEPENDS=	${CNEWSWRK}/conf/substitutions:${PORTSDIR}/${CNEWS_PORT}:configure
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcnews.a:${PORTSDIR}/${CNEWS_PORT} \
		gpg:${PORTSDIR}/security/gnupg

WRKSRC=		${WRKDIR}/c-nocem
CNEWS_PORT?=	news/cnews
#CNEWSWRK?=	${WRKDIRPREFIX}${PORTSDIR}/${CNEWS_PORT}/work
# ${.CURDIR}/../.. can be diffrent from ${PORTSDIR}
CNEWSWRK?=	${WRKDIRPREFIX}${.CURDIR}/../../${CNEWS_PORT}/work
NEWSBIN?=	${PREFIX}/libexec/cnews
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-cnews=${CNEWSWRK}
PLIST_SUB+=	NEWSBIN=${NEWSBIN:S=${PREFIX}/==}

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 500000
USE_PERL5=	yes
.endif

.include <bsd.port.post.mk>
