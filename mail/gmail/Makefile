# New ports collection makefile for:	gmime
# Date created:			14 Apr 2001
# Whom:				Bas Kruit <baskruit@bsltwr.dnsalias.org>
#
# $FreeBSD$
#

PORTNAME=	gmail
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://bsltwr.dnsalias.org/ftp/pub/gmail/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME client that stores email retrieved with pop in a mysql database

LIB_DEPENDS=	mysqlclient.10:${PORTSDIR}/databases/mysql323-client \
		gmime.6:${PORTSDIR}/mail/gmime

USE_X_PREFIX=	YES
USE_GMAKE=	YES
#USE_GNOME=	YES
USE_LIBTOOL_VER=13

BROKEN=		project is dead and port unmaintained
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2004-04-21

.include <bsd.port.mk>
