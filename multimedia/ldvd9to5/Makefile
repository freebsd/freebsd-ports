# New ports collection makefile for:	ldvd9to5
# Date created:		2004-10-03
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ldvd9to5
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://files.gff-clan.net/pub/ldvd/
DISTNAME=	${PORTNAME}-v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	fehlner@gmx.de
COMMENT=	Gui, which shall simplify shrinking a DVD-9 to a DVD-5

RUN_DEPENDS=	transcode:${PORTSDIR}/multimedia/transcode \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mkisofs:${PORTSDIR}/sysutils/cdrtools \
		ifo_dump:${PORTSDIR}/multimedia/ogle \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		buffer:${PORTSDIR}/misc/buffer \
		lsdvd:${PORTSDIR}/multimedia/lsdvd \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

BROKEN=		Unfetchable

USE_PERL=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
NO_BUILD=	yes
DATA=		INSTALL.de INSTALL.en README.de README.en COPYING

post-patch:
	@${REINPLACE_CMD} -e 's|LSDVD=/opt/ldvd9to5|LSDVD=${LOCALBASE}/bin|g' ${WRKSRC}/ldvd9to5.conf
	@${REINPLACE_CMD} -e 's|/opt|${LOCALBASE}/share|g' -e 's|/etc|${LOCALBASE}/etc|g' ${WRKSRC}/ldvd9to5

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${DATADIR}
	${MKDIR} ${DATADIR}/modules
	${CP} -rv ${WRKSRC}/modules ${DATADIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ldvd9to5.conf ${PREFIX}/etc
	cd ${WRKSRC} && ${INSTALL_SCRIPT} ldvd9to5 ${PREFIX}/bin

.include <bsd.port.mk>
