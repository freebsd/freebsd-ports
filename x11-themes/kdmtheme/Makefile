## New ports collection makefile for:   KDM theme manager
# Date created:			12 April 2005
# Whom:				illusia <illusia@inbox.lv>
#
# $FreeBSD$
#

PORTNAME=	kdmtheme
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11-themes
MASTER_SITES=	http://beta.smileaf.org/files/kdmtheme/ \
		${MASTER_SITE_GENTOO:S/%SUBDIR%/distfiles/}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	KDM Theme Manager

USE_KDEBASE_VER=3
USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_AUTOTOOLS=	automake:19:env autoconf:262:env libtool:15
USE_GMAKE=	yes

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${SH} admin/cvs.sh dist)

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
