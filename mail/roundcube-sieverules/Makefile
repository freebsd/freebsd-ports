# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	sieverules
PORTVERSION=	2.1.2
PORTEPOCH=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail sieve plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube>=1.0:${PORTSDIR}/mail/roundcube
RUN_DEPENDS=	roundcube>=1.0:${PORTSDIR}/mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	Roundcube-Plugin-SieveRules-Managesieve
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	f606c1a

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/sieverules

# This target is only meant to be used by the port maintainer.
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
