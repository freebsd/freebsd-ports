# New ports collection makefile for: altivore
# Date created:		08 Oct 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	altivore
PORTVERSION=	0.9.3
CATEGORIES=	security
MASTER_SITES=	http://www.robertgraham.com/altivore/ \
		http://www.networkice.com/altivore/
DISTNAME=	altivore
EXTRACT_SUFX=	.c

MAINTAINER=	jus@security.za.net

RESTRICTED=     License does not allow redistribution in any form\
		(source, code or otherwise)

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	@${PERL} -pi -e "s///" ${WRKDIR}/${DISTFILES}

do-install:
	@${MKDIR} ${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${WRKDIR}/${DISTFILES} \
		${PREFIX}/share/examples/${PORTNAME}
	@${INSTALL_DATA} ${PKGMESSAGE} \
		${PREFIX}/share/examples/${PORTNAME}/README

	@${SED} -e "s!/usr/local/!${PREFIX}/!" ${PKGMESSAGE}

.include <bsd.port.mk>
