# Ports collection makefile for:    netatalk
# Date created:         23 Jul 1997
# Whom:                 stb
#
# $FreeBSD$
#

PORTNAME=	netatalk
PORTVERSION=	1.5p6
CATEGORIES=	net print
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	netatalk
DISTNAME=	netatalk-1.5pre6

MAINTAINER=	marcus@marcuscom.com

.if !exists(/usr/include/tcpd.h)
LIB_DEPENDS=	wrap.7:${PORTSDIR}/security/tcp_wrapper
.endif

CONFIGURE_ARGS+=	--with-tcp-wrappers
# CONFIGURE_ARGS+=	--disable-admin-group
# CONFIGURE_ARGS+=	--disable-ddp
# CONFIGURE_ARGS+=	--with-shadow
# CONFIGURE_ARGS+=	--enable-lastdid
.if defined(NETATALK_WITH_PAM)
CONFIGURE_ARGS+=	--with-pam # broken
PLIST_SUB+=             NETATALKPAM=""
.else
PLIST_SUB+=             NETATALKPAM="@comment "
.endif
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
FILES=		AppleVolumes.default AppleVolumes.system afpd.conf \
		atalkd.conf netatalk.conf netatalk.pamd papd.conf
LINKS=		unbin unhex unsingle hqx2bin single2bin macbinary \
		binheader nadheader
MAN1=		achefile.1 aecho.1 afile.1 afppasswd.1 getzones.1 \
		megatron.1 nbp.1 pap.1 psorder.1 hqx2bin.1 macbinary.1 \
		nbplkup.1 nbprgstr.1 nbpunrgstr.1 papstatus.1 \
		single2bin.1 unbin.1 unhex.1 unsingle.1
MAN3=		atalk_aton.3 nbp_name.3
MAN4=		atalk.4
MAN5=		AppleVolumes.default.5 afpd.conf.5 atalkd.conf.5 \
		netatalk.conf.5 papd.conf.5
MAN8=		afpd.8 atalkd.8 pap.8 papd.8 papstatus.8 psf.8

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/netatalk.sh \
		> ${WRKSRC}/netatalk.sh

post-install:
	@${RM} -f ${PREFIX}/bin/nu ${PREFIX}/bin/lp2pap.sh
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

.include <bsd.port.mk>
