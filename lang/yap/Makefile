# ex:ts=8
# New ports collection makefile for:	yap
# Date created:			Apr 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yap
PORTVERSION=	4.3.19
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Yap-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/Yap-${PORTVERSION}/arch

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../configure

post-extract:
	@${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
