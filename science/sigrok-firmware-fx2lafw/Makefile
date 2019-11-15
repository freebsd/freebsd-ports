# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	firmware
PORTVERSION=	0.1.7
CATEGORIES=	science
MASTER_SITES=	http://sigrok.org/download/binary/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}/
PKGNAMEPREFIX=	sigrok-
PKGNAMESUFFIX=	-fx2lafw
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-bin-${PORTVERSION}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Cypress FX2 firmware for hardware logic analyzers

LICENSE=	GPLv2

NO_BUILD=	yes

FW_FILES=	fx2lafw-braintechnology-usb-lps.fw \
		fx2lafw-cwav-usbeeax.fw \
		fx2lafw-cwav-usbeedx.fw \
		fx2lafw-cwav-usbeesx.fw \
		fx2lafw-cwav-usbeezx.fw \
		fx2lafw-cypress-fx2.fw \
		fx2lafw-hantek-6022be.fw \
		fx2lafw-hantek-6022bl.fw \
		fx2lafw-sainsmart-dds120.fw \
		fx2lafw-saleae-logic.fw \
		fx2lafw-sigrok-fx2-16ch.fw \
		fx2lafw-sigrok-fx2-8ch.fw

PORTDOCS=	README NEWS
PLIST_FILES=	${FW_FILES:S,^,share/sigrok-firmware/,}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docfile in README NEWS
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${STAGEDIR}${DOCSDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/sigrok-firmware
.for fwfile in ${FW_FILES}
	${INSTALL_DATA} ${WRKSRC}/${fwfile} \
		${STAGEDIR}${PREFIX}/share/sigrok-firmware/
.endfor

.include <bsd.port.mk>
