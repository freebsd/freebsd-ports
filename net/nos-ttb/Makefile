# Created by: Edwin Groothuis
# $FreeBSD$

PORTNAME=	nos-ttb
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.djcbsoftware.nl/code/ttb/
DISTNAME=	ttb-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	NOS teletekst browser

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/pygtk-2.0.pc:x11-toolkits/py-gtk2

# there is a successor project called TTX at
# https://github.com/djcb/ttx
DEPRECATED=	does not work due to protocol changes
EXPIRATION_DATE=2017-02-20

NO_BUILD=	yes
USES=		python

PLIST_FILES=	bin/ttb \
		share/ttb/ttb.glade \
		share/ttb/ttb.png

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/ttb
	${INSTALL_SCRIPT} ${WRKSRC}/src/ttb ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/glade/ttb.glade ${STAGEDIR}${PREFIX}/share/ttb
	${INSTALL_DATA} ${WRKSRC}/images/ttb.png ${STAGEDIR}${PREFIX}/share/ttb

.include <bsd.port.mk>
