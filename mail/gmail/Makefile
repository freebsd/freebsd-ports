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

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		gmime.5:${PORTSDIR}/mail/gmime

USE_X_PREFIX=	YES
USE_GMAKE=	YES
USE_GTK=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

.include <bsd.port.mk>
