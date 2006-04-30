# New ports collection makefile for:	evolution-webcal
# Date created:				Mon Apr 26 18:08:00 CEST 2004
# Whom:					Koop Mast <kwm@rainbow-runner.nl>
#
# $FreeBSD$
#   $MCom: ports/www/evolution-webcal/Makefile,v 1.37 2006/04/15 06:53:55 marcus Exp $
#

PORTNAME=	webcal
PORTVERSION=	2.5.90
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
PKGNAMEPREFIX=	evolution-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Webcal(endar) handler for gnome

USE_X_PREFIX=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_PERL=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack evolutiondataserver libgnomeui
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	evolution-webcal.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
