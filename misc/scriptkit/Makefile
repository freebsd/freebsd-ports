# New ports collection makefile for:   scriptkit
# Version required:    0.1.6
# Date created:        22 April 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id$
#

DISTNAME=	ScriptKit-0.1.6
PKGNAME=        scriptkit-0.1.6
CATEGORIES=	misc
MASTER_SITES= 	ftp://ftp.aist-nara.ac.jp/pub/personal/masata-y/gyve/fullkit/gyve-0.1.2.4/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	goconfig:${PORTSDIR}/devel/guileobjc

GNU_CONFIGURE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
