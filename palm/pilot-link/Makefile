# New ports collection makefile for:    pilot-link
# Version required:     0.8.7
# Date created:         November, 1997
# Whom:                 Paul Traina <pst@freebsd.org>
#
# $Id: Makefile,v 1.4 1997/11/25 07:17:02 asami Exp $

DISTNAME=	pilot-link.0.8.7
PKGNAME=	pilot-link-0.8.7
CATEGORIES=	comms tk80
MASTER_SITES=	ftp://ryeham.ee.ryerson.ca/pub/PalmOS/

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	tk80\\.1:${PORTSDIR}/x11/tk80

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} < 300000
BROKEN=         libreadline
.endif

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=--with-perl5

MAN1=		dlpsh.1 ietf2datebook.1 install-datebook.1 \
		install-memo.1 install-user.1 pilot-xfer.1 \
		read-ical.1

.include <bsd.port.mk>
