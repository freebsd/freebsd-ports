# New ports collection makefile for: altivore
# Date created:		08 Oct 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	altivore
PORTVERSION=	0.9.3
CATEGORIES=	security
MASTER_SITES=	http://samy.kerneled.org/stuff/
DISTNAME=	altivore
EXTRACT_SUFX=	.c

MAINTAINER=	jus@security.za.net
COMMENT=	A publically disclosed (neither GPL nor open-source) ala Carnivore src

RESTRICTED=	License does not allow redistribution in any form\
		(source, code or otherwise)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s///" ${WRKDIR}/${DISTFILES}

do-install:
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${DISTFILES} \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${PKGMESSAGE} \
		${PREFIX}/share/examples/${PORTNAME}/README

	@${SED} -e "s!/usr/local/!${PREFIX}/!" ${PKGMESSAGE}

.include <bsd.port.mk>
