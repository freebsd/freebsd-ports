# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	veximaccountadmin
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://axel.sjostedt.no/misc/files/
PKGNAMEPREFIX=	roundcube-
DISTNAME=	rcube_plg_veximaccountadmin

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Roundcube vexim account admin plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=0.5:${PORTSDIR}/mail/roundcube

NO_BUILD=	yes

WWWDIR=		${PREFIX}/www/roundcube/plugins/veximaccountadmin
WRKSRC=		${WRKDIR}/veximaccountadmin

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
