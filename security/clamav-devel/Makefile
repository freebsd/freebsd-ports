# New ports collection makefile for:	clamav-devel
# Date created:				13 June 2003
# Whom:					Rob Evers <rob@debank.tv>
#
# $FreeBSD$
#

PORTNAME=	clamav
PORTVERSION=	20030720
CATEGORIES=	security
MASTER_SITES=	http://clamav.elektrapro.com/snapshot/ \
		http://clamav.essentkabel.com/snapshot/ \
		http://clamav.ozforces.com/ \
		http://clamav.rulez.pl/snapshot/
PKGNAMESUFFIX=	-devel

MAINTAINER=	rob@debank.tv
COMMENT=	Command line virus scanner written entirely in C

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha \
		unarj:${PORTSDIR}/archivers/unarj \
		unrar:${PORTSDIR}/archivers/unrar \
		zoo:${PORTSDIR}/archivers/zoo \
		arc:${PORTSDIR}/archivers/arc \
		unzip:${PORTSDIR}/archivers/unzip

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--disable-clamav --enable-bigstack

MAN1=		clamscan.1 freshclam.1 sigtool.1 clamdscan.1 clamav-milter.1
MAN5=		clamav.conf.5
MAN8=		clamd.8

.include <bsd.port.pre.mk>

.if defined(WITH_MILTER)
USE_GCC=	3.2
CONFIGURE_ARGS+=	--enable-milter
PLIST_SUB+=	CLAMAV-MILTER:=""
.else
PLIST_SUB+=	CLAMAV-MILTER:="@comment "
.endif

pre-install:
	@${ECHO} "===>  Creating custom user to run clamav..."
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	@${ECHO} "===>  Setting permissions..."
	@${SETENV} PKG_PREFIX=${PREFIX} ${sh} \
	${SH} ${PKGINSTALL} ${PREFIX} POST-INSTALL

.include <bsd.port.post.mk>
