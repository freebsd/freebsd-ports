# New ports collection makefile for:	cryptplug
# Date created:		29 Jan 2003
# Whom:			michaelnottebrock@gmx.net
#
# $FreeBSD$
#

PORTNAME=	cryptplug
PORTVERSION=	0.3.15
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/cryptplug/

MAINTAINER=	michaelnottebrock@gmx.net

BUILD_DEPENDS=	gpgme-config:${PORTSDIR}/security/gpgme \
		gpg-agent:${PORTSDIR}/security/newpg

USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
