# Created by: Meno Abels <meno.abels@adviser.com>
# $FreeBSD$

PORTNAME=	ucarp
PORTVERSION=	1.5.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.pureftpd.org/pub/pure-ftpd/misc/ucarp/ \
		http://download.pureftpd.org/pub/ucarp/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	Userlevel Common Address Redundancy Protocol

USE_BZIP2=	yes

OPTIONS_DEFINE=	SCRIPTS
OPTIONS_DEFAULT=SCRIPTS

SCRIPTS_DESC=	Install scripts to manage virtual IP

.include <bsd.port.options.mk>

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls

USE_RC_SUBR=	ucarp

PLIST_FILES=	sbin/ucarp

.if ${PORT_OPTIONS:MSCRIPTS}
PLIST_FILES+=	sbin/ucarp-up \
		sbin/ucarp-down
post-install:
		${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-up.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-up
		${INSTALL_SCRIPT} ${WRKSRC}/examples/bsd/vip-down.sh ${STAGEDIR}${PREFIX}/sbin/ucarp-down
.endif

.include <bsd.port.mk>
