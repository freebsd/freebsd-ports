# Ports collection makefile for:    netatalk-asun
# Version required:     netatalk-1.4b2-asun-2.0
# Date created:         07 Sep 1998
# Whom:                 stb@freebsd.org
#
# $Id: Makefile,v 1.2 1998/11/29 22:40:15 asami Exp $
#

DISTNAME=       netatalk-1.4b2+asun2.1.0
PKGNAME=	netatalk-1.4b2+asun-2.1.0
CATEGORIES=	net print
MASTER_SITES=   ftp://ftp.u.washington.edu/public/asun/

MAINTAINER=	stb@freebsd.org

BUILD_DEPENDS=	${PREFIX}/lib/libwrap.a:${PORTSDIR}/security/tcp_wrapper

MAN1=		aecho.1 getzones.1 megatron.1 nbp.1 pap.1 psorder.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN8=		afpd.8 atalkd.8 papd.8 psf.8

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
