# New ports collection makefile for:	libxml
# Version required:			0.99.5
# Date created:				28 September 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.5 1999/01/27 08:31:53 fenner Exp $
#

DISTNAME=	libxml-0.99.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	libxml

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
