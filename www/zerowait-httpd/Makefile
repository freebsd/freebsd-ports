# New ports collection makefile for:	0W-httpd
# Date created:				17 March 2005
# Whom:					Vsevolod Stakhov
#
# $FreeBSD$
#

PORTNAME=	zerowait-httpd
PORTVERSION=	0.7l
CATEGORIES=	www
MASTER_SITES=	http://www.0w.ru/httpd/
DISTNAME=	0W-httpd-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	vsevolod@highsecure.ru
COMMENT=	Lightweight and fast http server

USE_GMAKE=	yes
USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ARGS=	CFLAGS="${CFLAGS}" CPPFLAGS=-I..

post-patch:
	@${REINPLACE_CMD} -e "s,/var/0W,${PREFIX}," ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s,/var/0W,${PREFIX}," ${WRKSRC}/common/settings.h

post-install:
	@${INSTALL_SCRIPT} -m 755 ${FILESDIR}/0W-httpd.sh ${PREFIX}/etc/rc.d/0W-httpd.sh

.include <bsd.port.mk>
