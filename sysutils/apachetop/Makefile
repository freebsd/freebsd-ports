# New ports collection makefile for:	apachetop
# Date created:				30 Sep 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	apachetop
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Apache RealTime log stats

BUILD_DEPENDS=	${LOCALBASE}/bin/autoconf257:${PORTSDIR}/devel/autoconf257

GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		apachetop.1
PLIST_FILES=	sbin/apachetop

post-configure:
	${REINPLACE_CMD} \
		-e 's/--run autoconf$$/--run autoconf257/' \
		-e 's/--run autoheader$$/--run autoheader257/' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
