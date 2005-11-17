# New ports collection makefile for:	cups-smb-backend
# Date created:		12 November 2005
# Whom:			Andrew Pantyukhin <infofarmer@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cups-smb-backend
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	infofarmer@gmail.com
COMMENT=	A CUPS backend for printing to Windows servers

RUN_DEPENDS=	smbspool:${PORTSDIR}/net/samba3 \
		${LOCALBASE}/sbin/cupsd:${PORTSDIR}/print/cups-base

NO_BUILD=	yes
PLIST_FILES=	libexec/cups/backend/smb
SUB_FILES=	pkg-message

do-install:
	${LN} -fs ${PREFIX}/bin/smbspool ${PREFIX}/libexec/cups/backend/smb
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
