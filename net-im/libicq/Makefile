# New ports collection makefile for:   libicq
# Version required:		0.20
# Date Created:			31 Oct 1998
# Whom:				Seiichirou Hiraoka
#
# $Id: Makefile,v 1.1.1.1 1998/11/19 07:03:11 flathill Exp $
#

DISTNAME=	libicq-0.20
CATEGORIES=	devel
MASTER_SITES=	http://www.montana.com/gabriel/gicq/files/

MAINTAINER=	flathill@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
