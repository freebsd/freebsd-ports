# New ports collection makefile for:	ktelnet
# Date created:		14 May 1998
# Whom:			Hans Petter Bieker <hanspb@persbraten.vgs.no>
#
# $FreeBSD$
#

PORTNAME=	ktelnet
PORTVERSION=	2.0.43
PORTREVISION=	1
CATEGORIES=	net kde
MASTER_SITES=	http://www.spaghetti-code.de/download/ktelnet/
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

pre-patch:
	@${PERL} -pi -e 's|-lqt|-l${QTNAME}|g ; \
		 s|qt_libdir=NONE|qt_libdir=|g' ${WRKSRC}/configure

.include <bsd.port.mk>
