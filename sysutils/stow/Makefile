# ex:ts=8
# Ports collection makefile for:  stow
# Date created:			  6 June 2000
# Whom:				  Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=	stow
PORTVERSION=	1.3.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU version of Carnegie Mellon's "Depot" program

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

PLIST_FILES=	bin/stow
INFO=		stow

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/stow ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/stow.info ${PREFIX}/info

.include <bsd.port.mk>
