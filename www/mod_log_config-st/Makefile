# New ports collection makefile for:	mod_log_config-st
# Date created:				Sun May 2 2004
# Whom:					Clement Laforet <clement@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mod_log_config-st
PORTVERSION=	1.0
CATEGORIES=	www
# Original location: http://bitbrook.de/software/mod_log_mysql/mod_log_config.c
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A modified version of mod_log_config for apache2

WANT_APACHE=	2
AP_FAST_BUILD=	YES
AP_GENPLIST=	YES
SRC_FILE=	mod_log_config.c
SHORTMODNAME=	log_config
MODULENAME=	mod_log_config-st

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/www/apache2/Makefile.modules.3rd"
post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.post.mk>
