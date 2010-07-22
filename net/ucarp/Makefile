# New ports collection makefile for:   ucarp
# Date created:                2005-05-06
# Whom:                        Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	ucarp
PORTVERSION=	1.5.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/ucarp/ \
		http://download.pureftpd.org/pub/ucarp/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Userlevel Common Address Redundancy Protocol

USE_BZIP2=	yes

OPTIONS=	UCARP_SCRIPTS "Install scripts to manage virtual IP" on

.include <bsd.port.pre.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

USE_RC_SUBR=	ucarp

PLIST_FILES=	sbin/ucarp

.if defined(WITH_UCARP_SCRIPTS)
PLIST_FILES+=	sbin/ucarp-up \
		sbin/ucarp-down
post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-up.sh ${PREFIX}/sbin/ucarp-up
		${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-down.sh ${PREFIX}/sbin/ucarp-down
.endif

.include <bsd.port.post.mk>
