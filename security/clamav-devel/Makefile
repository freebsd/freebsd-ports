# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.20
CATEGORIES=	security
MASTER_SITES=	http://clamav.elektrapro.com/stable/

MAINTAINER=	markun@onohara.to

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-clamav --disable-pthreads

MAN1=		clamscan.1 freshclam.1 sigtool.1

pre-install:
	@${ECHO} "==>  Creating custom user to run clamav..."
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.mk>
