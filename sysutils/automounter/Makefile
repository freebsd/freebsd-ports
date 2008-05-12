# New ports collection makefile for:	automounter
# Date created:		26 March 2008
# Whom:			Dominic Fandrey <kamikaze@bsdforen.de>
#
# $FreeBSD$
#

PORTNAME=	automounter
PORTVERSION=	1.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	bsdadminscripts

MAINTAINER=	kamikaze@bsdforen.de
COMMENT=	Provides scripts to dynamically configure amd

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
NO_BUILD=	yes
MANCOMPRESSED=	no

.if defined(NOPORTDOCS)
NOPORTDOCS=	-nodoc
.else
MAN5=		automounter.conf.5
MAN8=		automounter.8
.endif

plist: patch
		cd ${WRKSRC}; ./list.sh -nodoc > ${PLIST}

do-install:
		@cd ${WRKSRC}; ./install.sh -prefix=${PREFIX} ${NOPORTDOCS}

.include <bsd.port.mk>
