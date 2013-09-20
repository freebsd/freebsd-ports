# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_config-st
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
# Original location: http://bitbrook.de/software/mod_log_mysql/mod_log_config.c
MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A modified version of mod_log_config for apache2


USE_APACHE=	22

AP_FAST_BUILD=	yes
SRC_FILE=	mod_log_config.c
SHORTMODNAME=	log_config
MODULENAME=	mod_log_config-st

NO_STAGE=	yes
post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
