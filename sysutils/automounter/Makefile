# New ports collection makefile for:	automounter
# Date created:		26 March 2008
# Whom:			Dominic Fandrey <kamikaze@bsdforen.de>
#
# $FreeBSD$
#

PORTNAME=	automounter
PORTVERSION=	1.3.4
CATEGORIES=	sysutils
MASTER_SITES=	SF/bsdadminscripts/${PORTNAME}

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Provides scripts to dynamically configure amd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
NO_BUILD=	yes
MANCOMPRESSED=	yes

.if defined(NOPORTDOCS)
NOPORTDOCS=	-nodoc
.else
MAN5=		automounter.conf.5
MAN8=		automounter.8
.endif

plist: patch
		@cd ${WRKSRC}; ./plist.sh -nodoc > ${PLIST}

do-install:
		@cd ${WRKSRC}; ./install.sh -prefix=${PREFIX} ${NOPORTDOCS}

.include <bsd.port.mk>
