# New ports collection makefile for:	mod_fcgid for Apache2
# Date created:		13 August 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_fcgid
PORTVERSION=	0.80
CATEGORIES=	www
MASTER_SITES=	http://fastcgi.coremail.cn/
DISTNAME=	${PORTNAME}.${PORTVERSION}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	An alternative FastCGI module for Apache2

USE_APACHE=	yes
WITH_APACHE2=	yes
MAKE_ARGS=	top_dir="${LOCALBASE}/share/apache2" INCLUDES="-I${LOCALBASE}/include/apache2"
INSTALL_TARGET=	install-modules

post-install:
	${MKDIR} -m 700 /var/run/fcgidsock
	${CHOWN} www:www /var/run/fcgidsock
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
