# $FreeBSD$

PORTNAME=	automatic_addressbook
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://code.crapouillou.net/attachments/download/19/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail automatic addressbook plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube>=0.8:${PORTSDIR}/mail/roundcube
RUN_DEPENDS=	roundcube>=0.8:${PORTSDIR}/mail/roundcube

USE_BZIP2=	yes
NO_BUILD=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}
RCDIR=	${PREFIX}/www/roundcube
WWWDIR=	${RCDIR}/plugins/automatic_addressbook

SUB_FILES=	pkg-message
SUB_LIST=	RCDIR=${RCDIR} PLUGINDIR=${WWWDIR}

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKSRC}; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
		${SED} -e "s,^\.,%%WWWDIR%%," >${WRKDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
		-e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
		-e "s,^\.,@dirrm %%WWWDIR%%," >>${WRKDIR}/pkg-plist.tmp

do-install:
	@${MKDIR} ${WWWDIR}
	@cd ${WRKSRC} && ${PAX} -r -w . ${WWWDIR}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
