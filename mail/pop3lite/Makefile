# New ports collection makefile for:   pop3lite
# Date created:        1 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pop3lite
PORTVERSION=	0.1.90
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	greid@ukug.uk.freebsd.org

USE_GLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

MAN5=		pop3lite.conf.5
MAN8=		pop3lite.8

post-patch:
	@ ${RM} ${WRKSRC}/doc/*.info

.include <bsd.port.mk>
