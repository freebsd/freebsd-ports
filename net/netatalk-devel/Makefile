# Ports collection makefile for:    netatalk
# Version required:     netatalk-1.4b2
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $Id: Makefile,v 1.6 1998/09/09 01:31:06 stb Exp $
#

DISTNAME=       netatalk-1.4b2
CATEGORIES=	net print
MASTER_SITES=   ftp://terminator.rs.itd.umich.edu/unix/netatalk/

PATCH_SITES=	http://www.umich.edu/~rsug/netatalk/patches/1.4b2/
PATCHFILES=	afpd-macos8.diff afpd-bfree.diff

MAINTAINER=	stb@freebsd.org

MAN1=		aecho.1 getzones.1 megatron.1 nbp.1 pap.1 psorder.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN8=		afpd.8 atalkd.8 papd.8 psf.8

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
