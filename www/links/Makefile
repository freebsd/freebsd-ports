# New ports collection makefile for:	links
# Version required:	0.82
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

DISTNAME=	links-0.82
CATEGORIES=	www
MASTER_SITES=	http://artax.karlin.mff.cuni.cz/~mikulas/vyplody/links/download/ \
		http://www.add.com.pl/download/

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/links ${PREFIX}/bin

.include <bsd.port.mk>
