# New ports collection makefile for:   libxml
# Version required:    0.99.3
# Date created:        28 September 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.4 1999/01/17 08:44:29 vanilla Exp $
#

DISTNAME=	libxml-0.99.3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	libxml

MAINTAINER=	nacai@iname.com

GNU_CONFIGURE=	yes

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
