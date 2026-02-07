PORTNAME=	gsmc
PORTVERSION=	1.1
PORTREVISION=	7
CATEGORIES=	science hamradio
MASTER_SITES=	http://www.qsl.net/ik5nax/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Smith chart program for impedance matching
WWW=		https://www.qsl.net/ik5nax

LICENSE=	GPLv2

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		autoreconf gmake gnome pkgconfig
PLIST_FILES=	bin/gsmc share/man/man1/gsmc.1.gz

post-patch:
	@${REINPLACE_CMD} '/^LIBS=/s/$$/ -lm/' ${WRKSRC}/Makefile.am

.include <bsd.port.mk>
