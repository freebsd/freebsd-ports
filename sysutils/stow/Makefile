# ex:ts=8
# Ports collection makefile for:  stow
# Date created:			  6 June 2000
# Whom:				  Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	stow
PORTVERSION=	1.3.2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	stow

MAINTAINER=	ports@FreeBSD.org

Y2K=		http://www.gnu.org/software/year2000.html

GNU_CONFIGURE=	yes

post-install:
	install-info ${PREFIX}/info/stow.info ${PREFIX}/info/dir

.include <bsd.port.mk>
