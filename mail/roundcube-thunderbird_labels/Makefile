# Created by: Alexander Moisseev <moiseev@mezonplus.ru>
# $FreeBSD$

PORTNAME=	thunderbird_labels
PORTVERSION=	0.8.1
CATEGORIES=	mail
MASTER_SITES=	http://rcmail-thunderbird-labels.googlecode.com/files/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	moiseev@mezonplus.ru
COMMENT=	Thunderbird Labels plugin for RoundCube webmail

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube>=0.5:${PORTSDIR}/mail/roundcube

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
WWWDIR?=	${PREFIX}/www/roundcube/plugins/${PORTNAME}

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
