# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	2.0.b2
PORTREVISION=	2
CATEGORIES=	net print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netatalk
DISTNAME=	${PORTNAME}-2.0-beta2

MAINTAINER=	marcus@FreeBSD.org
COMMENT=	File and print server for AppleTalk networks

LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
.if defined(WITH_SRVLOC)
LIB_DEPENDS+=	slp.1:${PORTSDIR}/net/openslp
.endif

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_ICONV=	yes
USE_RC_SUBR=	yes
CONFIGURE_ARGS+=	--with-tcp-wrappers \
			--with-pkgconfdir=${PREFIX}/etc \
			--with-libiconv=${LOCALBASE}
.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--with-pam=/etc/pam.d
PLIST_SUB+=		NETATALKPAM=""
.else
CONFIGURE_ARGS+=	--without-pam
PLIST_SUB+=		NETATALKPAM="@comment "
.endif
.if defined(WITH_SRVLOC)
# Enable Service Location Protocol support.  This allows MacOS X < 10.1 to
# pickup afpd servers in the network.
CONFIGURE_ARGS+=	--enable-srvloc=${LOCALBASE}
.endif
CONFIGURE_ARGS+=	--with-bdb=${LOCALBASE}
.if defined (WITH_TIMELORD)
CONFIGURE_ARGS+=	--enable-timelord
PLIST_SUB+=		TIMELORD=""
.else
PLIST_SUB+=		TIMELORD="@comment "
.endif
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
USE_PERL5=	yes
FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
		atalkd.conf papd.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		achfile.1 aecho.1 afile.1 afppasswd.1 getzones.1 \
		megatron.1 nbp.1 pap.1 psorder.1 hqx2bin.1 macbinary.1 \
		nbplkup.1 nbprgstr.1 nbpunrgstr.1 papstatus.1 \
		single2bin.1 unbin.1 unhex.1 unsingle.1 acleandir.1 \
		netatalk-config.1 timeout.1 apple_cp.1 apple_mv.1 \
		apple_rm.1 uniconv.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN5=		AppleVolumes.default.5 afpd.conf.5 atalkd.conf.5 \
		netatalk.conf.5 papd.conf.5
MAN8=		afpd.8 atalkd.8 cnid_dbd.8 cnid_metad.8 papd.8 papstatus.8 \
		psf.8 timelord.8

CONFLICTS=	bigloo-2.* cap-6.0.* tct-1.* netatalk-1*
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} RC_SUBR=${RC_SUBR}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Netatalk has the following tunable options:"
	@${ECHO_MSG} "		WITH_SRVLOC=yes		Enable Service Location Protocol support"
	@${ECHO_MSG} "		WITH_PAM=yes		Enable PAM support"
	@${ECHO_MSG} "		WITH_TIMELORD=yes	Enable Timelord network time service"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "See Netatalk's Makefile for more details on some of these options."
	@${ECHO_MSG} ""

post-extract:
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/netatalk.sh > ${WRKSRC}/netatalk.sh

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh \
		${PREFIX}/bin/test_parse_mtab \
		${PREFIX}/bin/afpd-mtab.pl ${PREFIX}/etc/netatalk.conf.dist
	${INSTALL_SCRIPT} ${WRKSRC}/netatalk.sh \
		${PREFIX}/etc/rc.d/netatalk.sh
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
