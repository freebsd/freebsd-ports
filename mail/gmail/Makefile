# New ports collection makefile for:	gmime
# Date created:			14 Apr 2001
# Whom:				Bas Kruit <baskruit@bsltwr.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	gmail
PORTVERSION=	0.7.0
CATEGORIES=	mail
MASTER_SITES=	http://gmail.linuxpower.org/

MAINTAINER=	baskruit@bsltwr.dnsalias.org

BROKEN=		"Does not build"

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		gmime.6:${PORTSDIR}/mail/gmime

USE_X_PREFIX=	YES
USE_GMAKE=	YES
USE_GNOME=	YES
USE_LIBTOOL=	YES

.include <bsd.port.mk>
