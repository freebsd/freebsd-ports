# Ports collection makefile for:    netatalk-asun
# Version required:     netatalk-1.4b2-asun-2.0
# Date created:         07 Sep 1998
# Whom:                 stb@freebsd.org
#
# $FreeBSD$
#

DISTNAME=       netatalk-1.4b2+asun2.1.3
PKGNAME=	netatalk-1.4b2+asun-2.1.3
CATEGORIES=	net print
MASTER_SITES=   ftp://ftp.u.washington.edu/public/asun/ \
		http://www.freebsd.org/~stb/mirror/ftp.u.washington.edu/public/asun/ \
		ftp://ftp.hanse.de/sites/transit/mirror/ftp.u.washington.edu/public/asun/

MAINTAINER=	stb@freebsd.org

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

MAKE_ARGS=	INSTALL="${INSTALL} ${COPY}"

.include <bsd.port.pre.mk>

.if defined(USE_SENDFILE) && ${OSVERSION} >= 310000
MAKE_ARGS+=	-DUSE_SENDFILE
.endif

.if defined(USE_CNID)
## Support for fixed DirIDs; probably broken.
BUILD_DEPENDS=	${PREFIX}/lib/libdb.a:${PORTSDIR}/databases/db
MAKE_ARGS+=	-DUSE_CNID
.endif

pre-build:
## sendfile(2) support seems to be broken in this version, but go ahead an try
## to fix it!
.if defined(USE_SENDFILE) && ${OSVERSION} < 310000
	@${ECHO_MSG} "***   sendfile(2) support is available only with FreeBSD 3.1-RELEASE"
	@${ECHO_MSG} "      or newer.  This port probably won't compile."
.endif
.if ${OSVERSION} >= 310000
.if defined(USE_SENDFILE)
	@${ECHO_MSG} "***   sendfile(2) support is experimental and will likely cause"
	@${ECHO_MSG} "      undesired behaviour!"
.else
#	@${ECHO_MSG} "***   Use -DUSE_SENDFILE to enable the experimental sendfile(2) support."
.endif
.endif

MAN1=		aecho.1 getzones.1 megatron.1 nbp.1 pap.1 psorder.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN8=		afpd.8 atalkd.8 papd.8 psf.8

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
