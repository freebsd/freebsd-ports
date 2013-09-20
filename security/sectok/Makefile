# Created by: Bruce M. Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sectok
PORTVERSION=	20030825
CATEGORIES=	security
MASTER_SITES=	http://www.citi.umich.edu/projects/smartcard/
DISTNAME=	sectok-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ISO 7816 Smartcard Utility

LIB_DEPENDS=	sectok.3:${PORTSDIR}/security/libsectok

USE_OPENSSL=	yes

USE_LDCONFIG=	yes
WRKSRC=         ${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		sectok.1
PLIST_FILES=	bin/sectok

NO_STAGE=	yes
.include <bsd.port.mk>
