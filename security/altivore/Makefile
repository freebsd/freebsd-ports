# New ports collection makefile for: altivore
# Date created:		08 Oct 2001
# Whom:			Justin Stanford <jus@security.za.net>
#
# $FreeBSD$
#

PORTNAME=	altivore
PORTVERSION=	0.9.3
CATEGORIES=	security
MASTER_SITES=	http://80.237.203.14/media/directory06/uploads/ \
		http://mirror.inerd.com/FreeBSD/distfiles/altivore/
DISTNAME=	altivore
EXTRACT_SUFX=	.c

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A publically disclosed (neither GPL nor open-source) ala Carnivore src

RESTRICTED=	License does not allow redistribution in any form\
		(source, code or otherwise)

SUB_FILES=	pkg-message

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s///" ${WRKDIR}/${DISTFILES}

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTFILES} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${PKGMESSAGE} ${EXAMPLESDIR}/README

.include <bsd.port.mk>
