# New ports collection makefile for:	cryptplug
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	cryptplug
PORTVERSION=	0.3.16
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/cryptplug

MAINTAINER=	lofi@freebsd.org
COMMENT=	A collection of plug-ins to cryptographic engines

BUILD_DEPENDS=	gpgme-config:${PORTSDIR}/security/gpgme \
		gpg-agent:${PORTSDIR}/security/newpg

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
