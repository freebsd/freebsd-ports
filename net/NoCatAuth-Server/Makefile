# New ports collection makefile for:    NoCatAuth
# Date created:         19 November 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Server
PORTVERSION=	0.82
CATEGORIES=	net
MASTER_SITES=	http://nocat.net/download/NoCatAuth/
PKGNAMEPREFIX=	NoCatAuth-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open 802.11 Authentication Server

RUN_DEPENDS= \
	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	NoCatAuth-Gateway-*

NO_BUILD=	yes
INSTALL_TARGET=	authserv

USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_SUBMAKE=	yes

WRAP_USER?=	nocat
NOCATDIR?=	nocat

MAKE_ARGS+=	DESTDIR=${PREFIX}/ PREFIX=${NOCATDIR}
MAKE_ARGS+=	WRAP_USER=${WRAP_USER}
MAKE_ARGS+=	-w

pre-install:
	@( ${FIND} ${WRKDIR} -type f -name '*.orig' -exec ${RM} '{}' ';' )
	@${SETENV} NOCAT_DIR="${PREFIX}/${NOCATDIR}" WRAP=${WRAP_USER} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
