# New ports collection makefile for:	cryptplug
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	cryptplug
PORTVERSION=	0.3.16
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GNUPG}
MASTER_SITE_SUBDIR=	alpha/cryptplug

MAINTAINER=	lofi@freebsd.org
COMMENT=	A collection of plug-ins to cryptographic engines

BUILD_DEPENDS=	gpgme-config:${PORTSDIR}/security/gpgme03 \
		gpg-agent:${PORTSDIR}/security/gnupg-devel

USE_INC_LIBTOOL_VER=13
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
