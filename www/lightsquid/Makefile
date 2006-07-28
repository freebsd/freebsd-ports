# New ports collection makefile for:	lightsquid
# Date created:				24 Nov 2005
# Whom:					Alexander Logvinov <info@logvinov.com>
#
# $FreeBSD$
#

PORTNAME=	lightsquid
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@logvinov.com
COMMENT=	A light and fast web based squid proxy traffic analyser

.if !defined(WITHOUT_GD)
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/GD.pm:${PORTSDIR}/graphics/p5-GD
.endif

NO_BUILD=	yes
USE_PERL5=	yes

DSTDIR?=	${PREFIX}/www/${PORTNAME}
SUB_LIST=	DSTDIR=${DSTDIR}
SUB_FILES=	pkg-message

do-patch:
	@${MV} ${WRKSRC}/lightsquid.cfg ${WRKSRC}/lightsquid.cfg.dist
	@${MV} ${WRKSRC}/group.cfg ${WRKSRC}/group.cfg.dist
	@${MV} ${WRKSRC}/realname.cfg ${WRKSRC}/realname.cfg.dist

do-install:
	@${MKDIR} ${DSTDIR}
	@${CP} -R ${WRKSRC}/ ${DSTDIR}
	@${CP} -n ${DSTDIR}/lightsquid.cfg.dist ${DSTDIR}/lightsquid.cfg
	@${CP} -n ${DSTDIR}/group.cfg.dist ${DSTDIR}/group.cfg
	@${CP} -n ${WRKSRC}/realname.cfg.dist ${DSTDIR}/realname.cfg
	@${CHMOD} +x ${DSTDIR}/*.cgi
	@${CHMOD} +x ${DSTDIR}/*.pl
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${DSTDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
