# Ports collection makefile for:   kadu
# Date created:        17 July 2003
# Whom:                Jacek Pelka <jacek@combit.com.pl>
#
# $FreeBSD$
#

PORTNAME=		kadu
PORTVERSION=		0.3.4
PORTREVISION=		2
PORTEPOCH=		1
CATEGORIES=		polish net
MASTER_SITES=		http://kadu.net/releases/
DISTNAME=		${PORTNAME}-${PORTVERSION}

MAINTAINER=		jacek@combit.com.pl
COMMENT=		QT Gadu-Gadu client

LIB_DEPENDS=		gadu.3:${PORTSDIR}/polish/ekg:install

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-existing-libgadu \
			--program-transform-name=''\
			--mandir=${PREFIX}/man
USE_QT_VER=		3

WRKSRC=			${WRKDIR}/${PORTNAME}

MAN1=			kadu.1
MANLANG=		pl
MANCOMPRESSED=		no

.include <bsd.port.mk>
