# New ports collection makefile for:	notmuch
# Date created:        11 February 2012
# Whom:                DarwinSurvivor <darwinsurvivor@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	notmuch
PORTVERSION=	0.11
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://notmuchmail.org/releases/

MAINTAINER=	darwinsurvivor@gmail.com
COMMENT=	Thread-based email index, search, and tagging application

LIB_DEPENDS=	gmime-2.4:${PORTSDIR}/mail/gmime24 \
		xapian:${PORTSDIR}/databases/xapian-core \
		talloc:${PORTSDIR}/devel/talloc

MAN1=		notmuch.1
MANCOMPRESSED=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--mandir=${MANPREFIX}/man
USE_GMAKE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
