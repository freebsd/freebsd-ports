# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups-samba
# Date created:		2004-02-10
# Whom:			John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	cups-samba
PORTVERSION=	5.0.r3
CATEGORIES=	print net
MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/windows/ \
		ftp://ftp2.easysw.com/pub/cups/windows/ \
		ftp://ftp3.easysw.com/pub/cups/windows/
DISTNAME=	${PORTNAME}-5.0rc3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Common UNIX Printing System:  MS Windows client drivers

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
		tardy:${PORTSDIR}/archivers/tardy \
		${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base \
		smbspool:${PORTSDIR}/net/samba
RUN_DEPENDS=	smbspool:${PORTSDIR}/net/samba \
		${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base \
		${LOCALBASE}/sbin/cupsaddsmb:${PORTSDIR}/print/cups-lpr \
		espgs:${PORTSDIR}/print/cups-pstoraster

USE_REINPLACE=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SH=		${LOCALBASE}/bin/bash

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		-e 's|%%TARDY%%|${LOCALBASE}/bin/tardy|g' \
		${WRKSRC}/cups-samba.install \
		${WRKSRC}/cups-samba.remove

do-install:
	cd ${WRKSRC} && ${SH} ${WRKSRC}/cups-samba.install now

post-install:
	@${CAT} ${PKGMESSAGE} | ${SED} 's|%%PREFIX%%|${PREFIX}|g'

.include <bsd.port.mk>
