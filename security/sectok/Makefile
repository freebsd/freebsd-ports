# New ports collection makefile for:	sectok
# Date created:		28 September 2003
# Whom:			Bruce M. Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sectok
PORTVERSION=	20030825
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
DISTNAME=	sectok-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	bms@FreeBSD.org
COMMENT=	ISO 7816 Smartcard Utility

LIB_DEPENDS=	sectok.3:${PORTSDIR}/security/libsectok

USE_OPENSSL=	yes

INSTALLS_SHLIB= yes
WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		sectok.1
PLIST_FILES=	bin/sectok

.include <bsd.port.mk>
