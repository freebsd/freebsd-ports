# New ports collection makefile for:	mod_cvs
# Date created:				14 August 2001
# Whom:					petef
#
# $FreeBSD$
#

PORTNAME=	mod_cvs
PORTVERSION=	0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		ftp://ftp.sub.nu/pub/mod_cvs/ \
		ftp://ftp.isk.kth.se/pub/people/main/mod_cvs/
MASTER_SITE_SUBDIR=	petef

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A module that makes Apache CVS aware

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	yes
USE_REINPLACE=	yes
MAKE_ARGS+=	APXS="${APXS}"

post-patch:
	@${REINPLACE_CMD} -e 's,apxs,${APXS},g' ${WRKSRC}/Makefile

do-install:
	${APXS} -i -A -n cvs ${WRKSRC}/mod_cvs.so
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
