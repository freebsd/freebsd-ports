# New ports collection makefile for:	iat
# Date created:		29 Mar 2007
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	iat
PORTVERSION=	0.1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Converter of many types of CD-ROM image file formats into ISO-9660

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/iat

.include <bsd.port.mk>
