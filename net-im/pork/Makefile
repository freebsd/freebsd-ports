# New ports collection makefile for:   pork
# Date created:			04 Feb 2003
# Whom:				Bob Bomar <bob@bomar.us>
#
# $FreeBSD$
#

PORTNAME=		pork
PORTVERSION=		0.99.8.1
CATEGORIES=		net-im
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ojnk

MAINTAINER=		wxs@FreeBSD.org
COMMENT=		Console-based AIM client

USE_PERL5=		yes
USE_OPENSSL=		yes

GNU_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes

post-patch:
	@${REINPLACE_CMD} -e 's/^inline //' ${WRKSRC}/src/*.h

.include <bsd.port.mk>
