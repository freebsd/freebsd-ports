# New ports collection makefile for:	libghttp
# Version required:			1.0.2
# Date Created:				24 Dec 1998
# Whom:					Vanilla I. Shu <vanilla@FreeBSD.ORG>
#
# $Id: Makefile,v 1.7 1999/03/27 10:35:57 vanilla Exp $
#

DISTNAME=	libghttp-1.0.2
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libghttp

MAINTAINER=	vanilla@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
