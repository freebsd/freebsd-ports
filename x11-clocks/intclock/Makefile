# New ports collection makefile for:	intclock
# Date created:		6 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	intclock
PORTVERSION=	2.12
CATEGORIES=	x11-clocks perl5
MASTER_SITES=	http://www.peterverthez.net/projects/${PORTNAME}/ CENKES

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Multi-timezone clock

BUILD_DEPENDS=	p5-Gtk2>=1.144:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		iso-codes>=1.3:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_PERL5=	yes
PERL_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|$$zonedir/$$countryfile|${LOCALBASE}/share/iso-codes/iso_3166.tab|' \
			${WRKSRC}/lib/Intclock/TZ.pm
	@${REINPLACE_CMD} -e 's|$$prefix/share/intclock|${DATADIR}|;\
		s|/usr/share|${PREFIX}/share|' ${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|;\
		s|/usr/share/intclock|${DATADIR}|' ${WRKSRC}/data/intclock.desktop
	@${FIND} ${WRKSRC} -name \*.bak -delete

pre-install:
	@${INSTALL} -d ${PREFIX}/share/applications/

.include <bsd.port.mk>
