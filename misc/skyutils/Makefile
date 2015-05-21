# Created by: Machiel Mastenbroek <machiel_mastenbroek@hotmail.com>
# $FreeBSD$

PORTNAME=	skyutils
PORTVERSION=	2.9
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	LOCAL/laszlof \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library required by smssend (same author)

USES=		libtool
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

.include <bsd.port.mk>
