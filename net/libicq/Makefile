# New ports collection makefile for:   libicq
# Version required:		0.20
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id$
#

DISTNAME=	libicq-0.20
PKGNAME=	libicq-0.20
CATEGORIES=	devel
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

MAINTAINER=	flathill@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
