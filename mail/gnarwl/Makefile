# New ports collection makefile for:	gnarwl
# Date created:				Mon Mar 29 2003
# Whom:					Xavier Beaudouin <kiwi@oav.net>
#
# $FreeBSD$
#

PORTNAME=	gnarwl
PORTVERSION=	3.3
CATEGORIES=	mail
MASTER_SITES=	http://www.oss.billiton.de/download/ \
		ftp://ftp.oav.net/pkg_freebsd/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kiwi@oav.net
COMMENT=	Email autoresponder that gets data from LDAP

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	${LOCALBASE}/bin/gsed:${PORTSDIR}/textproc/gsed

USE_GMAKE=	yes
USE_ICONV=	yes
USE_OPENLDAP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-docdir=${DOCSDIR}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN8=		damnit.8 gnarwl.8
MANCOMPRESSED=	yes

.include <bsd.port.mk>
