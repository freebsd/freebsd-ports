# New ports collection makefile for:    pilot-link
# Version required:     0.8.7
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id: Makefile,v 1.2 1997/11/24 09:38:13 pst Exp $

DISTNAME=	pilot-link.0.8.7
PKGNAME=	pilot-link-0.8.7
CATEGORIES=	comms tk80
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-perl5

MAN1=		dlpsh.1.gz ietf2datebook.1.gz install-datebook.1.gz \
		install-memo.1.gz install-user.1.gz pilot-xfer.1.gz \
		read-ical.1.gz

.include <bsd.port.mk>
