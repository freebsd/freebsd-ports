# $FreeBSD$

PORTNAME=	automatic_addressbook
PORTVERSION=	0.4.1
CATEGORIES=	mail
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail automatic addressbook plugin

LICENSE=	GPLv3

RUN_DEPENDS=	roundcube>=0.8:mail/roundcube

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	sblaisot

RCDIR=		${PREFIX}/www/roundcube
WWWDIR=		${RCDIR}/plugins/automatic_addressbook

SUB_FILES=	pkg-message
SUB_LIST=	RCDIR=${RCDIR} PLUGINDIR=${WWWDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>
