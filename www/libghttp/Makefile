# New ports collection makefile for:	libghttp
# Version required:			1.0.2
# Date Created:				24 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.5 1999/03/09 01:09:04 nectar Exp $
#

DISTNAME=	libghttp-1.0.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-1.0/sources

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
