# New ports collection makefile for:	muse
# Date created:				27 December 1999
# Whom:					freebsd@spatula.net
#
# $FreeBSD$
#

PORTNAME=	muse
PORTVERSION=	0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.spatula.net/muse/

MAINTAINER=	freebsd@spatula.net

MAN1=		muse.1
MANCOMPRESSED=	yes

pre-patch:
	${RM} -f ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

.include <bsd.port.mk>
