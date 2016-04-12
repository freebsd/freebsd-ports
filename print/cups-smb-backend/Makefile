# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cups-smb-backend
PORTVERSION=	1.0
PORTREVISION=	7
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CUPS backend for printing to Windows servers

RUN_DEPENDS=	smbspool:net/${SAMBA_PORT} \
		${LOCALBASE}/sbin/cupsd:print/cups

NO_BUILD=	yes
PLIST_FILES=	libexec/cups/backend/smb
SAMBA_PORT?=	samba36
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cups/backend
	${LN} -fs ${PREFIX}/bin/smbspool ${STAGEDIR}${PREFIX}/libexec/cups/backend/smb

.include <bsd.port.mk>
