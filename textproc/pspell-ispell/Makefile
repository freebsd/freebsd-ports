# New ports collection makefile for:	pspell-ispell
# Date created:				29th June 2000
# Whom:					Ade Lovett <ade@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pspell-ispell
PORTVERSION=	0.12
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pspell
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^0//}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell
LIB_DEPENDS=	pspell.15:${PORTSDIR}/textproc/aspell

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
