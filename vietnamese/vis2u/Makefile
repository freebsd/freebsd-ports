# ex:ts=8
# Ports collection makefile for:  vis2u
# Date created:			  Tue Nov 27, 2001
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	vis2u
PORTVERSION=	1.0
CATEGORIES=	vietnamese textproc
#MASTER_SITES=	http://www.geocities.com/~starkville/mozilla/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	obrien
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	VISCII->Unicode conversion

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

do-build:
	cd ${WRKSRC} ; make vis2u

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vis2u ${PREFIX}/bin

.include <bsd.port.mk>

EXTRACT_BEFORE_ARGS+=	-L
