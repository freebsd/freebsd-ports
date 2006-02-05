# New ports collection makefile for:	asterisk-oh323
# Date created:		17 Jun 2005
# Whom:			Andriy Pylypenko <bamby@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk-oh323
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.inaccessnetworks.com/projects/asterisk-oh323/download/

MAINTAINER=	bamby@portaone.com
COMMENT=	A H.323 support module for the Asterisk soft PBX

BUILD_DEPENDS= 	${NONEXISTENT}:${PORTSDIR}/devel/pwlib152:build \
	    	${NONEXISTENT}:${PORTSDIR}/net/openh323-112:build \
	    	${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes
MAKE_ENV=	MKDIR="${MKDIR}" \
		PWLIBDIR=${WRKDIRPREFIX}${PORTSDIR}/devel/pwlib152/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${PORTSDIR}/net/openh323-112/work/openh323 \
		CPP="${CXX}" \
		USE_OLD_CAPABILITIES_API="yes"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
