# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	1.4b2
PORTREVISION=	1
CATEGORIES=	net print
MASTER_SITES=   ftp://terminator.rs.itd.umich.edu/unix/netatalk/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.hanse.de/sites/transit/mirror/terminator.rs.itd.umich.edu/unix/netatalk/
MASTER_SITE_SUBDIR=	stb/mirror/terminator.rs.itd.umich.edu/unix/netatalk

PATCH_SITES=	http://www.umich.edu/~rsug/netatalk/patches/1.4b2/ \
		${MASTER_SITE_LOCAL} \
		ftp://ftp.hanse.de/sites/transit/mirror/www.umich.edu/%257Ersug/netatalk/patches/1.4b2/
PATCH_SITE_SUBDIR=	stb/mirror/www.umich.edu/%7Ersug/netatalk/patches/1.4b2/ \
PATCHFILES=	afpd-macos8.diff afpd-bfree.diff

MAINTAINER=	ports@freebsd.org

MAN1=		aecho.1 getzones.1 megatron.1 nbp.1 pap.1 psorder.1 hqx2bin.1 \
		macbinary.1 nbplkup.1 nbprgstr.1 nbpunrgstr.1 \
		papstatus.1 single2bin.1 unbin.1 unhex.1 unsingle.1

MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN8=		afpd.8 atalkd.8 papd.8 psf.8

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
