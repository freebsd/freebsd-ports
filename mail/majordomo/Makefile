# New ports collection makefile for:	majordomo
# Version required:	1.93
# Date created:		8 Jul 1996
# Whom:			james@nexis.net
#
# $Id$
#

DISTNAME=	majordomo-1.93
CATEGORIES+=	mail
MASTER_SITES=	ftp://ftp.greatcircle.com/pub/majordomo/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	james@nexis.net

# Needs to create a user and group
IS_INTERACTIVE= yes
NO_PACKAGE=	yes
ALL_TARGET=	default
INSTALL_TARGET=	install install-wrapper install-archive2

post-install:
	cp -p ${FILESDIR}/post-install-notes ${PREFIX}/majordomo/Doc

.include <bsd.port.mk>
