# New ports collection makefile for:	koffice-i18n-lt
# Date created:                         27 April 2003
# Whom:                                 Michael Nottebrock <michaelnottebrock@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	koffice-i18n
PORTVERSION=	1.2.1
CATEGORIES?=	misc kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	Attic/koffice-${PORTVERSION:S/.0//}/src/
PKGNAMEPREFIX=	lt-
DISTNAME=	${PORTNAME}-${PKGNAMEPREFIX:S/-$//}-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Lithuanian messages and documentation for koffice

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

DISTNAME_OVERRIDE=yes
USE_KDELIBS_VER=3
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
KDE_I18N=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PKGNAMEPREFIX:S/-//}

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.mk>
