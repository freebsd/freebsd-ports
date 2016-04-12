# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkdvd
PORTVERSION=	4.0.9
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://regis.damongeot.free.fr/tkdvd/dl/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GUI to dvd+rw-tools and cdrecord

RUN_DEPENDS=	growisofs:sysutils/dvd+rw-tools \
		cdrecord:sysutils/cdrtools

USES=		tk

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/tkdvd share/pixmaps/tkdvd.png
PORTDOCS=	*

DESKTOP_ENTRIES="TkDVD" \
		"Burn CD/DVD" \
		"tkdvd" \
		"tkdvd" \
		"AudioVideo;DiscBurning;" \
		true

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|' ${WRKSRC}/install.tcl \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|wish|${WISH}|' ${WRKSRC}/TkDVD.sh
	@${REINPLACE_CMD} -e 's|/dev/sr0|/dev/cd0|' ${WRKSRC}/TkDVD.sh \
		${WRKSRC}/src/save_load_options.tcl

do-build:
	cd ${WRKSRC} && ${TCLSH} install.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdvd-install.sh ${STAGEDIR}${PREFIX}/bin/tkdvd
	${INSTALL_DATA} ${WRKSRC}/icons/tkdvd-2-48.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/tkdvd.png
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${WRKSRC}/doc/c* \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
