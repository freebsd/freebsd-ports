# New ports collection makefile for:	adns
# Version required:		0.7
# Date created:			Mon Mar 3, 2000
# Whom:				Kostya Lukin <lukin@okbmei.msk.su>
#
# $FreeBSD$
#

DISTNAME=	adns-0.7
CATEGORIES=     net
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.chiark.greenend.org.uk/users/ian/adns/
MASTER_SITE_SUBDIR=	adns

MAINTAINER=	lukin@okbmei.msk.su

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	strip ${PREFIX}/bin/adnstest ${PREFIX}/bin/adnslogres ${PREFIX}/bin/adnshost

.include <bsd.port.mk>
