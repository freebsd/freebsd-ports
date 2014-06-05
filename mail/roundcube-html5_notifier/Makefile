# Created by: Koichiro IWAO <meta+ports@vmeta.jp>
# $FreeBSD$

PORTNAME=	html5_notifier
PORTVERSION=	0.5.2
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	HTML5 desktop notifier plugin for roundcube

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=1.0:${PORTSDIR}/mail/roundcube
BUILD_DEPENDS=	roundcube>=1.0:${PORTSDIR}/mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	kitist
GH_PROJECT=	html5_notifier
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	968f570

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/${PORTNAME}

x-generate-plist: build
	cd ${WRKSRC}; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${WRKDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${WRKDIR}/pkg-plist.tmp

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
