# New ports collection makefile for:	prelude-pflogger
# Date created:			19 May 2009
# Whom:				Anders Troback <freebsd@troback.com>
#
# $FreeBSD$

PORTNAME=	prelude-pflogger
DISTVERSION=	0.9.0-rc2
CATEGORIES=	security
MASTER_SITES=	http://www.prelude-ids.com/download/releases/${PORTNAME}/

MAINTAINER=	freebsd@troback.com
COMMENT=	Prelude-PFlogger Listens at OpenBSD PF

LIB_DEPENDS+=	prelude.19:${PORTSDIR}/security/libprelude

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_RC_SUBR=	prelude-pflogger

.include <bsd.port.mk>
