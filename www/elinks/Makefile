# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	elinks
PORTVERSION=	0.9.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://elinks.or.cz/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jharris@widomaker.com
COMMENT=	Elinks - links text WWW browser with enhancements

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_OPENSSL=	yes

MAN1=		elinks.1
MAN5=		elinkskeys.5 elinks.conf.5

.include <bsd.port.mk>
