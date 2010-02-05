# New ports collection makefile for:	evolution-webcal
# Date created:				Mon Apr 26 18:08:00 CEST 2004
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#   $MCom: ports/www/evolution-webcal/Makefile,v 1.64 2009/09/22 11:30:13 avl Exp $
#

PORTNAME=	evolution-webcal
PORTVERSION=	2.28.0
PORTREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Webcal(endar) handler for gnome

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL5=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	evolution-webcal.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
