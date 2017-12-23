# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cups-smb-backend
PORTVERSION=	1.0
PORTREVISION=	10
CATEGORIES=	print
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CUPS backend for printing to Windows servers

RUN_DEPENDS=	${LOCALBASE}/sbin/cupsd:print/cups

USES=		samba:run # smbspool
NO_BUILD=	yes
PLIST_FILES=	libexec/cups/backend/smb
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/cups/backend
	${LN} -fs ${PREFIX}/bin/smbspool ${STAGEDIR}${PREFIX}/libexec/cups/backend/smb

.include <bsd.port.mk>
