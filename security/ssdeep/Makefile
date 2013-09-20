# Created by: Nobutaka Mantani <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ssdeep
PORTVERSION=	2.9
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	A tool for computing context triggered piecewise hashes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAN1=		ssdeep.1

NO_STAGE=	yes
.include <bsd.port.mk>
