# New ports collection makefile for:	rpm
# Version required:	2.3.8
# Date created:		23 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1997/01/24 11:43:57 asami Exp $
#

DISTNAME=	rpm-2.3.8
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
