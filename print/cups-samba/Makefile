# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	cups-samba
# Date created:		2004-02-10
# Whom:			John Merryweather Cooper <coop9211@uidaho.edu>
#
# $FreeBSD$
#

PORTNAME=	cups-samba
PORTVERSION=	6.0
PORTREVISION=	7
CATEGORIES=	print net
MASTER_SITES=	${MASTER_SITE_EASYSW}
MASTER_SITE_SUBDIR=cups/windows
DISTNAME=	cups-windows-${PORTVERSION}-source

MAINTAINER=	mwisnicki+freebsd@gmail.com
COMMENT=	The Common UNIX Printing System:  MS Windows client drivers

RUN_DEPENDS=	smbspool:${PORTSDIR}/${SAMBA_PORT} \
		${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base

SAMBA_PORT?=	net/samba34

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

DATADIR=	${PREFIX}/share/cups
DRIVER_FILES=	cups6.inf cups6.ini cupsps6.dll cupsui6.dll

SUB_FILES=	pkg-message

pre-install:
	${MKDIR} ${DATADIR}/drivers

do-install:
	cd ${WRKSRC} && \
	for DRVFILE in ${DRIVER_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/cups-windows-${PORTVERSION}/i386/$${DRVFILE} ${DATADIR}/drivers; \
	done

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
