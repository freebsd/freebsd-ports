# Ports collection makefile for:    netatalk
# Version required:     netatalk-1.4b2
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $Id: Makefile,v 1.5 1998/02/27 00:05:23 stb Exp $
#

DISTNAME=       netatalk-1.4b2
CATEGORIES=	net print
MASTER_SITES=   ftp://terminator.rs.itd.umich.edu/unix/netatalk/

PATCH_SITES=	http://www.umich.edu/~rsug/netatalk/patches/1.4b2/
PATCHFILES=	afpd-macos8.diff afpd-bfree.diff

MAINTAINER=	stb@freebsd.org

MAN1=		aecho.1 getzones.1 megatron.1 nbp.1 pap.1 psorder.1
MLINKS=		hqx2bin.1 megatron.1 \
		macbinary.1 megatron.1 \
		single2bin.1 megatron.1 \
		unbin.1 megatron.1 \
		unhex.1 megatron.1 \
		unsingle.1 megatron.1 \
		nbplkup.1 nbp.1 \
		nbprgstr.1 nbp.1 \
		nbpunrgstr.1 nbp.1 \
		papstatus.1 pap.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN8=		afpd.8 atalkd.8 papd.8 psf.8

post-install:
	@PKG_PREFIX=${PREFIX} FAKE_PKG_INSTALL=yes \
		${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL
#	@if [ -f ${PREFIX}/etc/AppleVolumes.system ]; then \
#		echo "*** Make sure ${PREFIX}/etc/AppleVolumes.system is in sync with this version"; \
#		echo "    of the port.  See ${PREFIX}/etc/AppleVolumes.system.dist for details."; \
#	else \
#		${INSTALL_DATA} ${PREFIX}/etc/AppleVolumes.system.dist \
#			${PREFIX}/etc/AppleVolumes.system ; \
#	fi
#	@if [ -f ${PREFIX}/etc/AppleVolumes.default ]; then \
#		echo "*** Make sure ${PREFIX}/etc/AppleVolumes.default is in sync with this version"; \
#		echo "    of the port.  See ${PREFIX}/etc/AppleVolumes.default.dist for details."; \
#	else \
#		${INSTALL_DATA} ${PREFIX}/etc/AppleVolumes.default.dist \
#			${PREFIX}/etc/AppleVolumes.default ; \
#	fi

.include <bsd.port.mk>
