# New ports collection makefile for:   kwatch
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <zerium@webindex.no>
#
# $FreeBSD$
#

PORTNAME=	kwatch
PORTVERSION=	2.2.0
CATEGORIES=	misc kde
MASTER_SITES=	http://www.m-j-s.net/pub/kde/ \
		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/apps/utils

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=	2
GNU_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
