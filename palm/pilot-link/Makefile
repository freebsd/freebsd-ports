# New ports collection makefile for:    pilot-link
# Version required:     0.8.7
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id$

DISTNAME=	pilot-link.0.8.7
PKGNAME=	pilot-link-0.8.7
CATEGORIES=	comms tk80
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-perl5

.include <bsd.port.mk>
