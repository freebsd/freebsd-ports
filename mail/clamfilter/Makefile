# New ports collection makefile for:    clamfilter
# Date created:        11 Feb 2005
# Whom:                SeaD
#
# $FreeBSD$
#

PORTNAME=	clamfilter
PORTVERSION=	0.5
CATEGORIES=	mail
MASTER_SITES=	# disappeared

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A small, efficient clamav content filter for Postfix

DEPRECATED=		mastersites disappeared
EXPIRATION_DATE=	2006-11-05

RUN_DEPENDS=	${LOCALBASE}/bin/clamdscan:${PORTSDIR}/security/clamav

SUB_FILES=	pkg-message
PLIST_FILES=	bin/clamfilter

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
