# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mod_log_config-st
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	www
# Original location: http://bitbrook.de/software/mod_log_mysql/mod_log_config.c
# Please handle update requests with care!
# sheepkiller was hacked and not cleaned over a long periode.
# (First notice 2011-03 not cleaned until 2011-07)
# Provide distfile now from LOCAL
#MASTER_SITES=	http://sheepkiller.nerim.net/ports/${PORTNAME}/
MASTER_SITES=	LOCAL/ohauer
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Modified version of mod_log_config for apache2

EXPIRATION_DATE=	2014-02-08
DEPRECATED=	Upstream site gone since 2011-03

USE_APACHE=	22
AP_FAST_BUILD=	yes
SRC_FILE=	mod_log_config.c
SHORTMODNAME=	log_config
MODULENAME=	mod_log_config-st

.include <bsd.port.mk>
