# New ports collection makefile for:	rpm
# Version required:	2.5.5
# Date created:		30 April 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	rpm-2.5.5
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/

MAINTAINER=	ports@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
