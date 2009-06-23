# New ports collection makefile for:	foo2zjs
# Date created:		2006-03-17
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	foo2zjs
PORTVERSION=	20090530
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		${MASTER_SITE_LOCAL:S,$,acm/${PORTNAME}/,}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Driver for printers that use the ZjStream wire protocol

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base
RUN_DEPENDS=	${LOCALBASE}/share/foomatic/db/oldprinterids:${PORTSDIR}/print/foomatic-db \
		foomatic-rip:${PORTSDIR}/print/foomatic-filters

PROJECTHOST=	bsdistfiles
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes
SUB_FILES=	pkg-message

MAN1=	arm2hpdl.1 \
	foo2hiperc-wrapper.1 \
	foo2hiperc.1 \
	foo2hp.1 \
	foo2hp2600-wrapper.1 \
	foo2lava-wrapper.1 \
	foo2lava.1 \
	foo2oak-wrapper.1 \
	foo2oak.1 \
	foo2qpdl-wrapper.1 \
	foo2qpdl.1 \
	foo2slx-wrapper.1 \
	foo2slx.1 \
	foo2xqx-wrapper.1 \
	foo2xqx.1 \
	foo2zjs-pstops.1 \
	foo2zjs-wrapper.1 \
	foo2zjs.1 \
	hipercdecode.1 \
	lavadecode.1 \
	oakdecode.1 \
	opldecode.1 \
	printer-profile.1 \
	qpdldecode.1 \
	slxdecode.1 \
	usb_printerid.1 \
	xqxdecode.1 \
	zjsdecode.1 \

EXTRAFILES=	msexpand getweb
XML_FILES=	driver/foo2hiperc.xml \
		driver/foo2hp.xml \
		driver/foo2lava.xml \
		driver/foo2oak.xml \
		driver/foo2oak-z1.xml \
		driver/foo2qpdl.xml \
		driver/foo2slx.xml \
		driver/foo2xqx.xml \
		driver/foo2zjs.xml \
		printer/Generic-OAKT_Printer.xml \
		printer/Generic-ZjStream_Printer.xml \
		printer/HP-Color_LaserJet_1500.xml \
		printer/HP-Color_LaserJet_1600.xml \
		printer/HP-Color_LaserJet_2600n.xml \
		printer/HP-Color_LaserJet_CP1215.xml \
		printer/HP-LaserJet_1000.xml \
		printer/HP-LaserJet_1005.xml \
		printer/HP-LaserJet_1018.xml \
		printer/HP-LaserJet_1020.xml \
		printer/HP-LaserJet_1022.xml \
		printer/HP-LaserJet_M1005_MFP.xml \
		printer/HP-LaserJet_M1120_MFP.xml \
		printer/HP-LaserJet_P1005.xml \
		printer/HP-LaserJet_P1006.xml \
		printer/HP-LaserJet_P1007.xml \
		printer/HP-LaserJet_P1008.xml \
		printer/HP-LaserJet_P1505.xml \
		printer/HP-LaserJet_P2014.xml \
		printer/KONICA_MINOLTA-magicolor_2480_MF.xml \
		printer/KONICA_MINOLTA-magicolor_2490_MF.xml \
		printer/KONICA_MINOLTA-magicolor_2530_DL.xml \
		printer/Kyocera-KM-1635.xml \
		printer/Kyocera-KM-2035.xml \
		printer/Lexmark-C500.xml \
		printer/Minolta-Color_PageWorks_Pro_L.xml \
		printer/Minolta-magicolor_2200_DL.xml \
		printer/Minolta-magicolor_2300_DL.xml \
		printer/Minolta-magicolor_2430_DL.xml \
		printer/Oki-C3100.xml \
		printer/Oki-C3200.xml \
		printer/Oki-C3300.xml \
		printer/Oki-C3400.xml \
		printer/Oki-C3530_MFP.xml \
		printer/Oki-C5100.xml \
		printer/Oki-C5200.xml \
		printer/Oki-C5500.xml \
		printer/Oki-C5600.xml \
		printer/Oki-C5800.xml \
		printer/Samsung-CLP-300.xml \
		printer/Samsung-CLP-315.xml \
		printer/Samsung-CLP-600.xml \
		printer/Samsung-CLP-610.xml \
		printer/Samsung-CLX-2160.xml \
		printer/Samsung-CLX-3160.xml \
		printer/Samsung-CLX-3175.xml \
		printer/Xerox-Phaser_6110.xml \
		printer/Xerox-Phaser_6115MFP.xml

EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for FILES in ${XML_FILES}
EXTRACT_AFTER_ARGS+=	--exclude '${FILES}'
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS|CFLAGS?|g' -e 's|^PREFIX|PREFIX?|g' ${WRKSRC}/icc2ps/Makefile

post-install:
	@cd ${WRKSRC} && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1/ && \
			${INSTALL_SCRIPT} ${EXTRAFILES} ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ChangeLog README manual.pdf
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
