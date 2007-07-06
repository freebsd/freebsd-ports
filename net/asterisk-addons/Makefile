# New ports collection makefile for:	asterisk-addons
# Date created:				23 March 2006
# Whom:					Fabian Gast <fgast@only640k.org>
#
# $FreeBSD$
#

PORTNAME=	asterisk-addons
PORTVERSION=	1.4.2
CATEGORIES=	net
MASTER_SITES=	http://ftp.digium.com/pub/asterisk/releases/

MAINTAINER=	fgast@only640k.org
COMMENT=	GPL modules for the Asterisk Open Source PBX

BUILD_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk
RUN_DEPENDS=	asterisk:${PORTSDIR}/net/asterisk

OPTIONS=	SAMPLE_CONFIG	"Install sample configuration files" off

ONLY_FOR_ARCHS=	i386 amd64
USE_AUTOTOOLS=	libtool:15
USE_MYSQL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700000
BROKEN=	Does not build on 7-CURRENT
.endif

.if defined(WITH_SAMPLE_CONFIG)
PLIST_SUB+=	SAMPLE_CONFIG=""
.else
PLIST_SUB+=	SAMPLE_CONFIG="@comment "
.endif

post-install:
.if defined(WITH_SAMPLE_CONFIG)
	@cd ${WRKSRC} && ${GMAKE} samples
.endif

.include <bsd.port.post.mk>
