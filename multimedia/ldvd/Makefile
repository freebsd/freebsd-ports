# New ports collection makefile for:	ldvd9to5
# Date created:		2004-10-03
# Whom:			Andreas Fehlner <fehlner@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ldvd
PORTVERSION=	2.0.1
CATEGORIES=	multimedia
MASTER_SITES=	http://files.gff-clan.net/pub/ldvd/

MAINTAINER=	fehlner@gmx.de
COMMENT=	Gui, which shall simplify shrinking a DVD-9 to a DVD-5

RUN_DEPENDS=	transcode:${PORTSDIR}/multimedia/transcode \
		growisofs:${PORTSDIR}/sysutils/dvd+rw-tools \
		mkisofs:${PORTSDIR}/sysutils/cdrtools \
		ifo_dump:${PORTSDIR}/multimedia/ogle \
		dvdauthor:${PORTSDIR}/multimedia/dvdauthor \
		buffer:${PORTSDIR}/misc/buffer \
		lsdvd:${PORTSDIR}/multimedia/lsdvd \
		mplex:${PORTSDIR}/multimedia/mjpegtools \
		${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gtk.pm:${PORTSDIR}/x11-toolkits/p5-Gtk

USE_BZIP2=	yes
USE_PERL=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
DATA=		de.lang en.lang
PORTDOCS=	AUTHORS HISTORY README.de README.en
PLIST_FILES=	bin/ldvd etc/ldvd.conf.sample ${DATA:S|^|%%DATADIR%%/|}
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|ldvd-ls|lsdvd|g' \
		${WRKSRC}/ldvd.conf ${WRKSRC}/ldvd
	@${REINPLACE_CMD} -e 's|/usr/share/$$sh_name-$$version|${DATADIR}|g; \
		s|/etc|${PREFIX}/etc|g' ${WRKSRC}/ldvd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ldvd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ldvd.conf ${PREFIX}/etc/ldvd.conf.sample
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${DATA:S|^|${WRKSRC}/|} ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
