# Created by: Machiel Mastenbroek <machiel_mastenbroek@hotmail.com>
# $FreeBSD$

PORTNAME=	skyutils
PORTVERSION=	2.9
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library required by smssend (same author)

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf libtool
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

NO_STAGE=	yes
pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

.include <bsd.port.mk>
