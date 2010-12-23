# New ports collection makefile for:	downtimed
# Date created:				2010-09-06
# Whom:					Janne Snabb <snabb@epipe.com>
#
# $FreeBSD$
#

PORTNAME=	downtimed
PORTVERSION=	0.2
CATEGORIES=	sysutils
MASTER_SITES=	http://dist.epipe.com/${PORTNAME}/ \
		http://launchpadlibrarian.net/58217312/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	snabb@epipe.com
COMMENT=	System downtime monitoring and reporting tool

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XZ=		yes
MAN1=		downtimes.1
MAN8=		downtimed.8
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes

post-install:
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
