# New ports collection makefile for:	kdeadmin
# Date created:				5 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdeadmin
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

post-patch:
	@cd ${WRKSRC}/kpackage; \
	${PERL} -pi -e 's@^typedef[ \t]+__off64.*\n@@' \
		rpm*.h rpm*.c rpm*.cpp

.include <bsd.port.mk>
