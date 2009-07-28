# New ports collection makefile for:	tkdvd
# Date created:		01 Sep 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tkdvd
PORTVERSION=	4.0.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://regis.damongeot.free.fr/tkdvd/dl/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	GUI to dvd+rw-tools and cdrecord

RUN_DEPENDS=	growisofs:${PORTSDIR}/sysutils/dvd+rw-tools

USE_TCL=	84+
USE_TK=		84+
USE_CDRTOOLS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/tkdvd share/pixmaps/tkdvd.png
PORTDOCS=	*

DESKTOP_ENTRIES="TkDVD" \
		"Burn CD/DVD" \
		"tkdvd" \
		"tkdvd" \
		"" \
		true

post-patch:
	@${REINPLACE_CMD} -e 's|tclsh|${TCLSH}|' ${WRKSRC}/install.tcl \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|wish|${WISH}|' ${WRKSRC}/TkDVD.sh
	@${REINPLACE_CMD} -e 's|/dev/sr0|/dev/cd0|' ${WRKSRC}/TkDVD.sh \
		${WRKSRC}/src/save_load_options.tcl

do-build:
	cd ${WRKSRC} && ${TCLSH} install.tcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdvd-install.sh ${PREFIX}/bin/tkdvd
	${INSTALL_DATA} ${WRKSRC}/icons/tkdvd-2-48.png \
		${PREFIX}/share/pixmaps/tkdvd.png
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/FAQ ${WRKSRC}/doc/c* \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
