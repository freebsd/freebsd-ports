# New ports collection makefile for:	apachetop
# Date created:				30 Sep 2003
# Whom:					Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	apachetop
PORTVERSION=	0.12
CATEGORIES=	sysutils
MASTER_SITES=	http://clueful.shagged.org/apachetop/files/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	esn@x123.info
COMMENT=	Apache RealTime log stats

WANT_AUTOCONF_VER=257
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes

MAN1=		apachetop.1
PLIST_FILES=	sbin/apachetop

post-configure:
	${REINPLACE_CMD} \
		-e 's/--run autoconf$$/--run $${AUTOCONF}/' \
		-e 's/--run autoheader$$/--run $${AUTOHEADER}/' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
