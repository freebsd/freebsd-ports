# New ports collection makefile for:	kdeadmin
# Date created:				5 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeadmin
PORTVERSION=	2.2.1
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

pre-configure:
	${PERL} -pi -e "s@DO_NOT_COMPILE qt@DO_NOT_COMPILE kuser qt@g" ${WRKSRC}/configure
	find ${WRKSRC}/kpackage -name "*.cpp" -or -name "*.c" -or -name "*.h" \
		| xargs ${PERL} -pi -e "s#typedef __off64_t off64_t;##g"

.include <bsd.port.mk>
