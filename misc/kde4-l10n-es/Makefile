# New ports collection makefile for:	kde2-i18n
# Date created:				1 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kde-i18n
PORTVERSION=	2.1.1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER?=	demon@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_BZIP2=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes

PLIST=		${WRKDIR}/PLIST
SCRIPTS_ENV+=	PLIST=${PLIST}

pre-configure:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/Configure

.include <bsd.port.mk>
