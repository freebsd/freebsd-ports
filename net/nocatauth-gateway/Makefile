# New ports collection makefile for:    NoCatAuth
# Date created:         19 November 2003
# Whom:                 Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nocatauth-gateway
PORTVERSION=	0.82
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://nocat.net/download/NoCatAuth/
DISTNAME=	NoCatAuth-${PORTVERSION}

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Open 802.11 Authentication Gateway

RUN_DEPENDS= \
	${LOCALBASE}/sbin/pfctl:${PORTSDIR}/security/pf
RUN_DEPENDS= \
	${LOCALBASE}/bin/gpg:${PORTSDIR}/security/gnupg

CONFLICTS=	nocatauth-server-*

USE_PERL5_RUN=	yes
USE_GMAKE=	yes
USE_SUBMAKE=	yes

WRAP_USER?=	nocat
NOCATDIR?=	nocat

MAKE_ENV+=	FIREWALL=pf
MAKE_ENV+=	FW_BIN=pfctl
MAKE_ENV+=	FW_BINARY=${LOCALBASE}/sbin/pfctl
MAKE_ARGS+=	DESTDIR=${PREFIX}/ PREFIX=${NOCATDIR}
MAKE_ARGS+=	WRAP_USER=${WRAP_USER}
MAKE_ARGS+=	-w

ALL_TARGET=	wrapper
INSTALL_TARGET=	suid-gateway

pre-install:
	@( ${FIND} ${WRKDIR} -type f -name '*.orig' -exec ${RM} '{}' ';' )
	@${SETENV} NOCAT_DIR="${PREFIX}/${NOCATDIR}" WRAP_USER=${WRAP_USER} \
		${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
