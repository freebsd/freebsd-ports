# New ports collection makefile for:	libsectok
# Date created:		29 September 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsectok
PORTVERSION=	20030619
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
DISTNAME=	libsectok-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	ISO 7816 Smartcard API Library

INSTALLS_SHLIB=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_OPENSSL=	YES

MAN3=		sectok.3

IGNORE=		produces a broken package (dangling symlink)
EXPIRATION_DATE=2005-02-18
DEPRECATED=	"${IGNORE}"

.include <bsd.port.mk>
