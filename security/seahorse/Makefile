# New ports collection makefile for:	Seahorse
# Date created:		08 March 2000
# Whom:			Dave McKay <dave@mu.org>
#
# $FreeBSD$
#

PORTNAME=	seahorse
PORTVERSION=	0.4.9
CATEGORIES=	security
MASTER_SITES=	http://seahorse.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dave@mu.org

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}"
MAN1=		seahorse.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/seahorse ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/seahorse.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
