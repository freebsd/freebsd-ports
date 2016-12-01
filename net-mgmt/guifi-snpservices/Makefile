# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		snpservices
DISTVERSION=		0.2.2-8
PORTREVISION=		1
CATEGORIES=		net-mgmt www
MASTER_SITES=		http://serveis.guifi.net/debian/guifi/ \
			http://www.potion-studios.com/
PKGNAMEPREFIX=		guifi-
DISTNAME=		${PORTNAME}_${DISTVERSION}

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		Graphics server for the guifi.net meshnet

RUN_DEPENDS=		mrtg:net-mgmt/mrtg \
			rrdtool:databases/rrdtool

USE_PHP=		gd simplexml dom

SNPSERVICES_TMPDIR?=	/var/tmp/${PORTNAME}
SUB_FILES=		pkg-install pkg-deinstall pkg-message
SUB_LIST=		SNPSERVICES_TMPDIR=${SNPSERVICES_TMPDIR}

WRKSRC=			${WRKDIR}/${PORTNAME}-0.2.2
NO_BUILD=		yes

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete;

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} \
		&& ${COPYTREE_SHARE} \* ${STAGEDIR}${WWWDIR})
	${FIND} ${STAGEDIR}${WWWDIR} -type f -exec ${CHMOD} 644 {} +

.include <bsd.port.mk>
