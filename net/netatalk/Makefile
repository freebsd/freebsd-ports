# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	1.5p7
PORTREVISION=	1
CATEGORIES=	net print
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netatalk
DISTNAME=	netatalk-1.5pre7

MAINTAINER=	marcus@marcuscom.com

.if defined(WITH_CNID)
LIB_DEPENDS=	db3.2:${PORTSDIR}/databases/db3
.endif
.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS+=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc
.if defined(WITH_PAM)
PLIST_SUB+=             NETATALKPAM=""
.else
CONFIGURE_ARGS+=		--without-pam
PLIST_SUB+=             NETATALKPAM="@comment "
.endif
.if defined(WITH_CNID)
# Configure EXPERIMENTAL CNID DID support.  This is an attmept to make
# DIDs more persistent by using a Berkeley database to store the DID values.
# This should hopefully allow aliases to work between restarts of afpd.
# This has been tested on MacOS 9.2.1.  I have not gotten working on OS X.
CONFIGURE_ARGS+=		--enable-cnid-db \
						--with-db3=/usr/local
.else
# This method of DID calculation is not persistent, but has been tested to
# work with MacOS X (10.0.4) as well as MacOS 7-9.2.1.
CONFIGURE_ARGS+=		--with-did=last
.endif
USE_AUTOCONF=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=   configure
USE_GMAKE=	yes
FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
		atalkd.conf papd.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		achfile.1 aecho.1 afile.1 afppasswd.1 getzones.1 \
		megatron.1 nbp.1 pap.1 psorder.1 hqx2bin.1 macbinary.1 \
		nbplkup.1 nbprgstr.1 nbpunrgstr.1 papstatus.1 \
		single2bin.1 unbin.1 unhex.1 unsingle.1 acleandir.1 \
		netatalk-config.1 timeout.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN5=		AppleVolumes.default.5 afpd.conf.5 atalkd.conf.5 \
		netatalk.conf.5 papd.conf.5
MAN8=		afpd.8 atalkd.8 pap.8 papd.8 papstatus.8 psf.8

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/netatalk.sh \
		> ${WRKSRC}/netatalk.sh

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh \
		${PREFIX}/etc/netatalk.pamd.dist ${PREFIX}/bin/test_parse_mtab \
		${PREFIX}/bin/afpd-mtab.pl ${PREFIX}/etc/netatalk.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/netatalk.sh ${PREFIX}/etc/rc.d/netatalk.sh
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
