# New ports collection makefile for:   man2web
# Date created:                2003-04-19
# Whom:                        Christian Weisgerber <naddy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	man2web
PORTVERSION=	0.87
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR= ${PORTNAME}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	Convert man pages to HTML

GNU_CONFIGURE=	yes
CONFIGURE_TARGET= --build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS= --bindir="${PREFIX}/${CGIDIR}" \
		--sysconfdir="${PREFIX}/etc"

PLIST_SUB=	CGIDIR="${CGIDIR}"

CGIDIR=	www/cgi-bin

MAN1=	man2web.1
MAN5=	man2web.conf.5

.include <bsd.port.mk>
