# New ports collection makefile for:    clamfilter
# Date created:        11 Feb 2005
# Whom:                SeaD
#
# $FreeBSD$
#

PORTNAME=	clamfilter
PORTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	http://www.ensita.net/products/clamfilter/ \
		http://ftp.osuosl.org/pub/FreeBSD/distfiles/

MAINTAINER=	sead@mail.ru
COMMENT=	A small, efficient clamav content filter for Postfix

RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav

SUB_FILES=	pkg-message
PLIST_FILES=	bin/clamfilter

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
