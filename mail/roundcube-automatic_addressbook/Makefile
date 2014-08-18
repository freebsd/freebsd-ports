# $FreeBSD$

PORTNAME=	automatic_addressbook
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://code.crapouillou.net/attachments/download/19/
PKGNAMEPREFIX=	roundcube-

MAINTAINER=	anes@anes.su
COMMENT=	Roundcube webmail automatic addressbook plugin

LICENSE=	GPLv3

BUILD_DEPENDS=	roundcube>=0.8:${PORTSDIR}/mail/roundcube
RUN_DEPENDS=	roundcube>=0.8:${PORTSDIR}/mail/roundcube

USES=	tar:bzip2
NO_BUILD=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}
RCDIR=		${PREFIX}/www/roundcube
WWWDIR=		${RCDIR}/plugins/automatic_addressbook

SUB_FILES=	pkg-message
SUB_LIST=	RCDIR=${RCDIR} PLUGINDIR=${WWWDIR}

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	cd ${WRKSRC} && ${PAX} -r -w . ${STAGEDIR}${WWWDIR}
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
