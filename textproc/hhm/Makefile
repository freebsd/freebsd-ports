# New ports collection makefile for:	hhm
# Date created:	   27 February 2005
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	hhm
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://bonedaddy.net/pabs3/hhm/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	skv@FreeBSD.org
COMMENT=	HTML Help Maker

LIB_DEPENDS=	lzxcomp.1:${PORTSDIR}/archivers/liblzxcomp

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
MAKE_ENV=	PREFIX=${PREFIX}
USE_REINPLACE=	yes

PLIST_FILES=	bin/hhm

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.prev
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's!^typedef unsigned.*$$!!' ${WRKSRC}/hhm.c

.include <bsd.port.mk>
