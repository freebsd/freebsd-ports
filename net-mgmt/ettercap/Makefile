# New ports collection makefile for:   ettercap
# Date created:        19 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	ettercap
PORTVERSION=	0.6.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	greid@FreeBSD.org

GNU_CONFIGURE=	yes

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-doc
.endif

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN8=		ettercap.8

.include <bsd.port.mk>
