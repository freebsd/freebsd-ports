# New ports collection makefile for:	calife
# Date created:				13 Jun 2000
# Whom:					Thomas Quinot <thomas@cuivre.fr.eu.org>
#
# $FreeBSD$
#

PORTNAME=	calife
PORTVERSION=	2.8.5
CATEGORIES=	security
MASTER_SITES=	ftp://postfix.eu.org/pub/calife/

MAINTAINER=	thomas@FreeBSD.org
COMMENT=	A lightweight alternative to sudo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	"--with-etcdir=$(PREFIX)/etc"

MAN1=		calife.1
MAN5=		calife.auth.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

.include <bsd.port.post.mk>
