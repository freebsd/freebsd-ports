# Created by: Anes Muhametov <anes@anes.su>
# $FreeBSD$

PORTNAME=	sieverules
PORTVERSION=	0.9.0
PORTEPOCH=	1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail sieve plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=0.9.0:${PORTSDIR}/mail/roundcube

USE_GITHUB=	yes
GH_ACCOUNT=	JohnDoh
GH_PROJECT=	Roundcube-Plugin-SieveRules-Managesieve
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	430d810

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/sieverules

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKSRC}; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${.CURDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${.CURDIR}/pkg-plist.tmp

do-install:
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${WWWDIR}

.include <bsd.port.mk>
