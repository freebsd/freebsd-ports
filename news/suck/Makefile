# New ports collection makefile for:	suck
# Date created:		30 Mar 1996
# Whom:			graphite@taurus.bekkoame.or.jp
#
# $FreeBSD$
#

PORTNAME=	suck
PORTVERSION=	4.2.5
CATEGORIES=	news
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=     system/news/transport

MAINTAINER=	jseger@FreeBSD.org

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		suck.1 rpost.1 testhost.1 lmove.1

.if defined(NEWSBIN)
EXTRA_PATCHES+=	${FILESDIR}/cnews.patch
.else
EXTRA_PATCHES+=	${FILESDIR}/inn2.patch
BUILD_DEPENDS+=	${NONEXISTENT}:${PORTSDIR}/news/inn:configure
BUILD_DEPENDS+=	${LOCALBASE}/news/lib/libinn.a:${PORTSDIR}/news/inn
.endif

post-patch:
	@${PERL5} -pi -e "s=/usr/local/=${LOCALBASE}/=" ${WRKSRC}/Makefile.in
	@${PERL5} -pi -e "s=/usr/local/lib/suck=${PREFIX}/lib/suck=" \
		${WRKSRC}/suck_config.h
	@${PERL5} -pi -e "s=/usr/local/news/lib=${LOCALBASE}/news/lib=" \
		${WRKSRC}/suck_config.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.inn ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/get.news.generic ${PREFIX}/share/examples/suck
	${INSTALL_SCRIPT} ${WRKSRC}/sample/put.news ${PREFIX}/share/examples/suck
	${INSTALL_DATA} ${WRKSRC}/sample/*.sample ${PREFIX}/share/examples/suck
.endif

.include <bsd.port.mk>
