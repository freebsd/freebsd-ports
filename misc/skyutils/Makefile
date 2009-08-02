# ports collection makefile for:	skyutils
# Date created:				21 February 2004
# Whom: 				Machiel Mastenbroek <machiel_mastenbroek@hotmail.com>
#
# $FreeBSD$
#

PORTNAME=	skyutils
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	laszlof

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library required by smssend (same author)

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

pre-configure:
	@${REINPLACE_CMD} -e's/[[:cntrl:]]*$$//' ${WRKSRC}/src/skyutils.h

.include <bsd.port.mk>
