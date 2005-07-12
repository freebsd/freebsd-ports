# New ports collection makefile for:	asterisk-oh323
# Date created:		17 Jun 2005
# Whom:			Andriy Pylypenko <bamby@portaone.com>
#
# $FreeBSD$
#

PORTNAME=	asterisk-oh323
PORTVERSION=	0.6.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.inaccessnetworks.com/projects/asterisk-oh323/download/

MAINTAINER=	bamby@portaone.com
COMMENT=	A H.323 support module for the Asterisk soft PBX

BUILD_DEPENDS= 	${NONEXISTENT}:${PORTSDIR}/devel/pwlib:build \
	    	${NONEXISTENT}:${PORTSDIR}/net/openh323:build \
	    	${LOCALBASE}/sbin/asterisk:${PORTSDIR}/net/asterisk

USE_GMAKE=	yes

PLIST_FILES=	lib/liboh323wrap_s.a
PLIST_FILES+=	lib/asterisk/modules/chan_oh323.so
PLIST_FILES+=	etc/asterisk/oh323.conf.sample

MAKE_ENV=	MKDIR="${MKDIR}" \
		PWLIBDIR=${WRKDIRPREFIX}${PORTSDIR}/devel/pwlib/work/pwlib \
		OPENH323DIR=${WRKDIRPREFIX}${PORTSDIR}/net/openh323/work/openh323 \
		CPP="${CXX}"

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
