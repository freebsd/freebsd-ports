# New ports collection makefile for:    spell-1.0
# Date created:         Wed Apr 24 10:17:36 EDT 2002
# Whom:                 Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=		spell
PORTVERSION=		1.0
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GNU} \
			http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/
MASTER_SITE_SUBDIR=	spell

MAINTAINER=		brian@quynh-and-brian.org

RUN_DEPENDS=		${LOCALBASE}/bin/ispell:${PORTSDIR}/textproc/ispell

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--prefix=${PREFIX}

post-install:
	install-info ${PREFIX}/info/spell.info ${PREFIX}/info/dir

.include <bsd.port.mk>
