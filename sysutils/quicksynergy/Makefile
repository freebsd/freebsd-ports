# New ports collection makefile for:	quicksynergy
# Date created:		2008-03-28
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quicksynergy
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	lme@FreeBSD.org
COMMENT=	A graphical interface for easily configuring Synergy2

BUILD_DEPENDS=	synergys:${PORTSDIR}/sysutils/synergy

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 libglade

BROKEN=		does not build
DEPRECATED=	has been broken for more than 6 months
EXPIRATION_DATE=2009-01-19

PLIST_FILES=	bin/quicksynergy

pre-configure:
	@${REINPLACE_CMD} 's|ac_default_prefix=/usr/local|ac_default_prefix=${PREFIX}|' ${WRKSRC}/configure

.include <bsd.port.mk>
