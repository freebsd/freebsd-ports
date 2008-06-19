# New ports collection makefile for:   kleansweep
# Date created:        10 Februar 2008
# Whom:                tomsan
#
# $FreeBSD$
#

PORTNAME=	kleansweep
PORTVERSION=	0.2.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://linux.bydg.org/~yogin/

MAINTAINER=	thomas.sander@gmx.de
COMMENT=	KleanSweep allows you to reclaim disk space by finding unneeded files

USE_BZIP2=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_KDELIBS_VER=3

post-extract:
	(cd ${WRKSRC} && ${TAR} xzf admin/scons-mini.tar.bz2)

do-configure:
	(cd ${WRKSRC} && ./scons configure prefix=${PREFIX})

do-build:
	(cd ${WRKSRC} && ./scons)

do-install:
	(cd ${WRKSRC} && ./scons install)

.include <bsd.port.mk>
