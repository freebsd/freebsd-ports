# New ports collection makefile for:	kdeadmin
# Date created:				5 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeadmin
PORTVERSION=	2.2
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src

MAINTAINER=	demon@FreeBSD.org

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

pre-configure:
	${PERL} -pi -e "s@DO_NOT_COMPILE qt@DO_NOT_COMPILE kuser qt@g" ${WRKSRC}/configure

.include <bsd.port.mk>
