# Created by: darius@dons.net.au
# $FreeBSD$

PORTNAME=	nstreams
PORTVERSION=	1.0.4
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.hsc.fr/ressources/outils/nstreams/download/ \
		http://falafel.200ok.org/distfiles/nstreams/

MAINTAINER=	ecu@200ok.org
COMMENT=	Analyses network traffic and produces ipfw rules to allow it

BROKEN=		unfetchable

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nstreams \
		etc/nstreams-networks.sample \
		etc/nstreams-services \
		man/man1/nstreams.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/nstreams ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/nstreams.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-networks \
		${STAGEDIR}${PREFIX}/etc/nstreams-networks.sample
	${INSTALL_DATA} ${WRKSRC}/docs/nstreams-services \
		${STAGEDIR}${PREFIX}/etc/nstreams-services

.include <bsd.port.mk>
