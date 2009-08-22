# New ports collection makefile for:	quicksynergy
# Date created:		2008-03-28
# Whom:			Lars Engels <lme@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quicksynergy
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/Linux/${PORTVERSION}

MAINTAINER=	rnoland@FreeBSD.org
COMMENT=	A graphical interface for easily configuring Synergy2

BUILD_DEPENDS=	synergys:${PORTSDIR}/sysutils/synergy

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix libglade2

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/quicksynergy \
		share/locale/pt_BR/LC_MESSAGES/quicksynergy.mo

.include <bsd.port.mk>
