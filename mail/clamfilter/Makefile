# New ports collection makefile for:    clamfilter
# Date created:        11 Feb 2005
# Whom:                SeaD
#
# $FreeBSD$
#

PORTNAME=	clamfilter
PORTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.ensita.net/products/clamfilter/

MAINTAINER=	sead@mail.ru
COMMENT=	A small, efficient clamav content filter for Postfix

RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav

PKGMESSAGE=	${WRKSRC}/pkg-message
PLIST_FILES=	bin/clamfilter

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${FILESDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
