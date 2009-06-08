# New ports collection makefile for:   kleansweep
# Date created:        10 Februar 2008
# Whom:                tomsan
#
# $FreeBSD$
#

PORTNAME=	kleansweep
PORTVERSION=	0.2.9
PORTREVISION=	3
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
post-patch:
# `as' is reserved word in python 2.6, rename module
	@cd ${WRKSRC}/scons-local-0.96.1/SCons/Tool && ${MV} as.py asm.py
	@${REINPLACE_CMD} -e 's|as\.gen|asm.gen|; /import/ s|as|asm|' \
		${WRKSRC}/scons-local-0.96.1/SCons/Tool/gas.py

do-configure:
	(cd ${WRKSRC} && ./scons configure prefix=${PREFIX})

do-build:
	(cd ${WRKSRC} && ./scons)

do-install:
	(cd ${WRKSRC} && ./scons install)

.include <bsd.port.mk>
