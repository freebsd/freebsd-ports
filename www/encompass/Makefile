# Ports collection Makefile for:	encompass
# Date created:				26 July 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	encompass
PORTVERSION=	0.4.5
PORTREVISION=	3
CATEGORIES=	www gnome
MASTER_SITES=	http://elysium.zoned.net/${PORTNAME}/ \
		http://encompass.sourceforge.net/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	neon.23:${PORTSDIR}/www/neon

USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gtkhtml
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

post-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
