# New ports collection makefile for:	sieverues
# Date created:				Mon 17 Mar 2011
# Whom:					Anes Muhametov
#
# $FreeBSD$
#

PORTNAME=	sieverules
PORTVERSION=	1.17
CATEGORIES=	mail
MASTER_SITES=	http://www.tehinterweb.co.uk/roundcube/plugins/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	${PORTNAME}

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail sieve plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=0.8:${PORTSDIR}/mail/roundcube

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
