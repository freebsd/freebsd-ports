# New ports collection makefile for:	tinybsd
# Date created:		11 July 2005
# Whom:			Jean Milanez Melo <jmelo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tinybsd
PORTVERSION=	0.8
CATEGORIES=	sysutils
MASTER_SITES=	http://www.tinybsd.org/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	garga/${PORTNAME}

MAINTAINER=	jmelo@FreeBSD.org
COMMENT=	Shell script to build embedded systems based on FreeBSD

NO_BUILD=	yes
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/tinybsd

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
