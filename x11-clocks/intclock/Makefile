# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intclock
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	x11-clocks perl5
MASTER_SITES=	http://www.peterverthez.net/projects/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-timezone clock

BUILD_DEPENDS=	p5-Gtk2>=1.144:x11-toolkits/p5-Gtk2
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} \
		-e 's|$$zonedir/$$countryfile|/usr/share/misc/iso3166|' \
		${WRKSRC}/lib/Intclock/TZ.pm
	@${REINPLACE_CMD} \
		-e 's|$$prefix/share/intclock|${DATADIR}|' \
		-e 's|/usr/share|$$(DESTDIR)${PREFIX}/share|' \
		-e 's|DATADIR = $$datadir|DATADIR = $$(DESTDIR)$$datadir|' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} \
		-e 's|/usr/bin|${PREFIX}/bin|' \
		-e 's|/usr/share/intclock|${DATADIR}|' \
		${WRKSRC}/data/intclock.desktop
	@${FIND} ${WRKSRC} -name \*.bak -delete

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/applications/

.include <bsd.port.mk>
