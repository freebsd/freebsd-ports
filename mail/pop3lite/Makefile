# New ports collection makefile for:   pop3lite
# Date created:        1 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pop3lite
PORTVERSION=	0.2.4a
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A flexible, modular RFC-compliant POP3 daemon

USE_GNOME=	glib12
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN5=		pop3lite.conf.5
MAN8=		pop3lite.8

pre-build:
	@${LN} -sf ${LIBTOOL} ${WRKSRC}/libtool

.include <bsd.port.mk>
