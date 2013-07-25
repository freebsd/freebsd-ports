# Created by: Mark Felder <feld@freebsd.org>
# $FreeBSD$

PORTNAME=	login_info
DISTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	https://www.std-soft.de/webmail/plugins/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	${PORTNAME}_rc0.5_v${DISTVERSION}

MAINTAINER=	feld@freebsd.org
COMMENT=	Roundcube login info plugin

LICENSE=	GPLv2

RUN_DEPENDS=	roundcube>=0.5:${PORTSDIR}/mail/roundcube

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/login_info
WRKSRC=		${WRKDIR}/login_info

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKSRC}; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${.CURDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${.CURDIR}/pkg-plist.tmp

do-install:
	@${ECHO} "Installing in ${WWWDIR}"
	${MKDIR} ${WWWDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} \* ${WWWDIR}

.include <bsd.port.mk>
