# New ports collection makefile for:	clamav
# Date created:		15 July 2002
# Whom:			markun@onohara.to
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	0.54
CATEGORIES=	security
MASTER_SITES=	http://clamav.elektrapro.com/stable/

MAINTAINER=	markun@onohara.to
COMMENT=	Command line virus scanner written entirely in C

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
HAS_CONFIGURE=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-clamav --disable-pthreads

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1
MAN5=		clamav.conf.5
MAN8=		clamd.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
EXTRA_PATCHES=	${FILESDIR}/patch5-*
.endif

pre-install:
	@${ECHO} "==>  Creating custom user to run clamav..."
#	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

.include <bsd.port.post.mk>
