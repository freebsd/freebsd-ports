# New ports collection makefile for:	gtkyahoo
# Date created:			18 August 1999
# Whom:				dannyman@dannyland.org
#
# $FreeBSD$
#

PORTNAME=	gtkyahoo
PORTVERSION=	0.18.3
PORTREVISION=	4
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yahoo Messenger Client using GTK

USE_GNOME=	gtk12
USE_BISON=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386

post-patch:
	@${REINPLACE_CMD} -e '/@INSTALL@/s/$$INSTALL/${INSTALL}/; \
		s/echo aout/echo elf/' \
		${WRKSRC}/libyahoo/configure

.include <bsd.port.mk>
