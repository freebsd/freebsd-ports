# New ports collection makefile for:    pilot-link
# Version required:     0.8.7
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id: Makefile,v 1.21 1998/09/30 04:52:30 dima Exp $

DISTNAME=	pilot-link.0.9.0
PKGNAME=	pilot-link-0.9.0
CATEGORIES=	comms pilot tk80
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	dima@freebsd.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80

BROKEN_ELF=	bad shared library version numbers

USE_PERL5=	yes
PREFIX=		${LOCALBASE}/pilot
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-perl5=${PERL5}

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 \
		install-memo.1 install-user.1 pilot-xfer.1 \
		read-ical.1
MAN7=		pilot-link.7

.include <bsd.port.mk>
