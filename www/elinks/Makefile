# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	elinks
PORTVERSION=	0.3.2
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc

MAINTAINER=	jharris@widomaker.com

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--program-prefix=e
USE_GMAKE=	yes
USE_BZIP2=	yes

MAN1=		elinks.1

.include <bsd.port.mk>
