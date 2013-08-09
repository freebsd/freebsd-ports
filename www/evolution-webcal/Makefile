# Created by: Koop Mast <kwm@rainbow-runner.nl>
# $FreeBSD$
#   $MCom: ports/www/evolution-webcal/Makefile,v 1.69 2010/09/29 12:56:07 kwm Exp $

PORTNAME=	evolution-webcal
PORTVERSION=	2.32.0
PORTREVISION=	3
CATEGORIES=	www gnome
MASTER_SITES=	GNOME
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Webcal(endar) handler for gnome

USE_BZIP2=	yes
USES=		gettext gmake pathfix perl5
USE_PERL5=	build
USE_GNOME=	gnomeprefix intlhack evolutiondataserver libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	evolution-webcal.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|@mkdir_p@|mkdir -p|g' \
		${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's|glib-2.0 >= 2.8|glib-2.0 >= 2.8 gthread-2.0|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
