# New ports collection makefile for:	libxml
# Version required:			1.0.0
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.8 1999/03/09 01:09:03 nectar Exp $
#

DISTNAME=	libxml-1.0.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/libxml

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
