# New ports collection makefile for:   pidgin-msn-pecan
# Date created:		30 July 2008
# Whom:			hrkfrd@gmail.com
#
# $FreeBSD$
#

PORTNAME=	msn-pecan
PORTVERSION=	0.1.0.r1
CATEGORIES=	net-im
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	pidgin-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/-rc/}

MAINTAINER=	hrkfdn@gmail.com
COMMENT=	Alternative MSN protocol plugin for libpurple

LIB_DEPENDS=	purple.6:${PORTSDIR}/net-im/libpurple

PROJECTHOST=	msn-pecan
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

post-install:
	${GMAKE} -C ${WRKSRC} install_locales

.include <bsd.port.mk>
