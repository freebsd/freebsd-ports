# Created by: Hung-Yi Chen <gaod@hychen.org>
# $FreeBSD$

PORTNAME=	watchlist
PORTVERSION=	1.0.${SVN_REV}
PORTREVISION=	2
CATEGORIES=	www devel python
MASTER_SITES=	http://distfiles.cse.tw/ \
		http://trac-hacks.org/changeset/${SVN_REV}/watchlistplugin?old_path=/&format=zip&filename=/
PKGNAMEPREFIX=	trac-
DISTNAME=	${PORTNAME}plugin-r${SVN_REV}

MAINTAINER=	gaod@hychen.org
COMMENT=	Watchlist feature for wikis and tickets of Trac

LICENSE=	BSD

SVN_REV=	11526

RUN_DEPENDS+=	tracd:${PORTSDIR}/www/trac

WRKSRC=		${WRKDIR}/${PORTNAME}plugin/0.12
USES=		zip
USE_PYTHON=	2
USE_PYDISTUTILS=	easy_install

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
PYDISTUTILS_PKGNAME=	TracWatchlistPlugin
PYDISTUTILS_PKGVERSION=	${PORTVERSION:C/.${SVN_REV}//g}

post-extract:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${CHMOD} 644
	@${FIND} ${WRKSRC} -type d | ${XARGS} ${CHMOD} 755

.include <bsd.port.mk>
