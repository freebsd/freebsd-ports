# New ports collection makefile for:    nocatauth-server
# Date created:         19 November 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nocatauth-server
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nocat.net/download/NoCatAuth/
DISTNAME=	NoCatAuth-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open 802.11 Authentication Server

RUN_DEPENDS= \
	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	nocatauth-gateway-*

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
