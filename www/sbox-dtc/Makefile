# Ports collection makefile for:        dtc
# Date created:                 12 January 2005
# Whom:                         Thomas Goirand
#
# $FreeBSD$
#

PORTNAME=	sbox-dtc
PORTVERSION=	1.07.3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.gplhost.com/pub/sbox-dtc/bsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CGI wrapper for Web site hosting services to safely grant CGI

SBOX_UIDMIN?=	1000
SBOX_GIDMIN?=	1000
SBOX_SAFEPATH?=	/bin:/usr/bin:${PREFIX}/bin:${LOCALBASE}/bin
SBOX_LOGFILE?=	/var/log/httpd-suexec.log

CFLAGS+=	-DWEB_USER='\"${WWWOWN}\"' \
		-DWEB_GROUP='\"${WWWGRP}\"' \
		-DUID_MIN='\"${SBOX_UIDMIN}\"' \
		-DGID_MIN='\"${SBOX_GIDMIN}\"' \
		-DSAFE_PATH='\"${SBOX_SAFEPATH}\"' \
		-DLOG_FILE='\"${SBOX_LOGFILE}\"'

MAKE_ARGS=	CC="${CC}" COPTS="${CFLAGS}" \
		INSTALL_DIRECTORY=${PREFIX}/www/cgi-bin

PLIST_FILES=	www/cgi-bin/sbox
PLIST_DIRS=	www/cgi-bin

.include <bsd.port.mk>
