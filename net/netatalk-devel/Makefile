# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	1.5.0
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	net print
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netatalk

MAINTAINER=	marcus@marcuscom.com

.if defined(WITH_CNID)
LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3
.endif
.if defined(WITH_SRVLOC)
LIB_DEPENDS=	slp.1:${PORTSDIR}/net/openslp
.endif
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

USE_BZIP2=	yes
CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
#			--disable-ddp
.if defined(WITH_PAM)
PLIST_SUB+=             NETATALKPAM=""
.else
CONFIGURE_ARGS+=		--without-pam
PLIST_SUB+=             NETATALKPAM="@comment "
.endif
.if defined(WITH_SRVLOC)
# Enable Service Location Protocol support.  This allows MacOS X < 10.1 to
# pickup afpd servers in the network.
CONFIGURE_ARGS+=		--enable-srvloc
.endif
.if defined(WITH_FLOCK_LOCKS)
# Disable byte locking, and do full file locking.  This _may_ help with some
# Quark Express save issues.
CONFIGURE_ARGS+=		--with-flock-locks
.endif
.if defined(WITH_CNID)
# Configure EXPERIMENTAL CNID DID support.  This is an attmept to make
# DIDs more persistent by using a Berkeley database to store the DID values.
# This should hopefully allow aliases to work between restarts of afpd.
# This has been tested on MacOS 9.2.x and OS X.
CONFIGURE_ARGS+=		--with-did=cnid \
						--with-db3=/usr/local
.else
# This method of DID calculation is not persistent, but has been tested to
# work with MacOS X (10.0.3-10.1.1) as well as MacOS 7-9.2.2.
CONFIGURE_ARGS+=		--with-did=last
.endif
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
		atalkd.conf papd.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		achfile.1 aecho.1 afile.1 afppasswd.1 getzones.1 \
		megatron.1 nbp.1 pap.1 psorder.1 hqx2bin.1 macbinary.1 \
		nbplkup.1 nbprgstr.1 nbpunrgstr.1 papstatus.1 \
		single2bin.1 unbin.1 unhex.1 unsingle.1 acleandir.1 \
		netatalk-config.1 timeout.1 apple_cp.1 apple_mv.1 \
		apple_rm.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN5=		AppleVolumes.default.5 afpd.conf.5 atalkd.conf.5 \
		netatalk.conf.5 papd.conf.5
MAN8=		afpd.8 atalkd.8 pap.8 papd.8 papstatus.8 psf.8 timelord.8

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/netatalk.sh \
		> ${WRKSRC}/netatalk.sh

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh \
		${PREFIX}/bin/test_parse_mtab \
		${PREFIX}/bin/afpd-mtab.pl ${PREFIX}/etc/netatalk.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/netatalk.sh \
		${PREFIX}/etc/rc.d/netatalk.sh.sample
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/macusers/macusers \
		${PREFIX}/bin/macusers
.for i in ${FILES}
	[ -f ${PREFIX}/etc/${i} ] || \
		${INSTALL_DATA} -c ${PREFIX}/etc/${i}.dist ${PREFIX}/etc/${i}
.endfor
.for i in ${LINKS}
	( cd ${PREFIX}/bin && ${LN} -sf megatron ${i} )
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
