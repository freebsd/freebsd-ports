# New ports collection makefile for:	rpm
# Version required:	2.5.1
# Date created:		23 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.16 1998/10/28 12:06:26 tg Exp $
#

DISTNAME=	rpm-2.5.1
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.redhat.com/pub/redhat/code/rpm/ \
		ftp://ftp.uni-bayreuth.de/pub/linux/redhat/code/rpm/ \
		ftp://mirror.nucba.ac.jp/mirror/redhat/code/rpm/ \
		ftp://ftp.cdrom.com/pub/linux/redhat/code/rpm/

MAINTAINER=	tg@FreeBSD.ORG

BUILD_DEPENDS=	${PREFIX}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${BSD_INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--disable-nls
USE_GMAKE=	yes
MAN8=		rpm.8 rpm2cpio.8

pre-install:
	${MKDIR} ${PREFIX}/include/rpm

.include <bsd.port.mk>
