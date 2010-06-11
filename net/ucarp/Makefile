# New ports collection makefile for:   ucarp
# Date created:                2005-05-06
# Whom:                        Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	ucarp
PORTVERSION=	1.5.2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/ucarp/ \
		http://download.pureftpd.org/pub/ucarp/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Userlevel Common Address Redundancy Protocol

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

USE_RC_SUBR=	ucarp

PLIST_FILES=	sbin/ucarp

.include <bsd.port.mk>
