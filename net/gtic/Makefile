# New ports collection makefile for:	gtic
# Version required:	1.3b
# Date created:		22 August 1999
# Whom:			Denis Shaposhnikov <dsh@vlink.ru>
#
# $Id$
#

DISTNAME=	gtic-1.3b
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cracksoft.kiev.ua/pub/linux/gtic/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/fido

MAINTAINER=	dsh@vlink.ru

do-install:
	${MKDIR} ${PREFIX}/etc/gtic
.for i in areagroups areas config domains help users
	${INSTALL_DATA} ${WRKSRC}/etc/${i} ${PREFIX}/etc/gtic/${i}.sample
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtic ${PREFIX}/sbin/

.include <bsd.port.mk>
