# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <ringworm@inbox.lv>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.2.3
PORTREVISION=	0
#-----------------------------------------
#for local use, remove before submitting PR
CATEGORIES=		sysutils
#CATEGORIES=		local/sysutils
#VALID_CATEGORIES+=	${CATEGORIES}	# for FreeBSD to accept our local category
#-----------------------------------------
#MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
#MASTER_SITE_SUBDIR=	portmanager
MASTER_SITES=		http://www.pkix.net/mirror/sf.net/

MAINTAINER=		reso3w83@verizon.net
COMMENT=		FreeBSD port management software

.if defined(WITH_DEBUG)
BUILD_DEPENDS=	autoheader259:${PORTSDIR}/devel/autoconf259	\
	aclocal19:${PORTSDIR}/devel/automake19	\
	libtoolize15:${PORTSDIR}/devel/libtool15
.endif

MAN1=			portmanager.1
MAN3=			libMG.3 		\
			MGdbCreate.3		\
			MGdbGetRecordQty.3	\
			MGdbGoTop.3		\
			MGdbSeek.3

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
# Need INSTALL_TARGET to install /usr/local/etc/portmanager/pm-020.conf.SAMPLE
INSTALL_TARGET=		install info

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g ;	\
	s|0.2.3|${PORTVERSION}_${PORTREVISION}|g ;	\
	s|%%PORTSDIR%%|${PORTSDIR}|g ;	\
	s|%%PKG_DBDIR%%|${PKG_DBDIR}|g' ${WRKSRC}/libPMGR/src/libPMGR.h

# Only way to get WITH_DEBUG build dependencies handled prior to reconfiguring
# is to use post-configure <sigh>
post-configure:
.if defined(WITH_DEBUG)
	@${REINPLACE_CMD} -e 's|# BDECFLAGS=|BDECFLAGS=|g' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -e 's|# CFLAGS=|CFLAGS=|g' ${WRKSRC}/configure.ac
	cd ${WRKSRC};sh rePackage.sh;sh configure
.endif

post-install:
	@${ECHO}	"******************************************************"
	@${ECHO}	"* to compile with debug support try:                 *"
	@${ECHO}	"*   make WITH_DEBUG=yes install clean                *"
	@${ECHO}	"*                                                    *"
	@${ECHO}	"* portmanager commands:                              *"
	@${ECHO}	"*                                                    *"
	@${ECHO}	"* portmanager -h   brief help screen                 *"
	@${ECHO}	"*             -s   list status of installed ports    *"
	@${ECHO}	"*             -u   upgrade installed ports           *"
	@${ECHO}	"*                                                    *"
	@${ECHO}	"* see man portmanager(1) or                          *"
	@${ECHO}	"* /usr/local/etc/portmanager/pm-020.conf             *"
	@${ECHO}	"* for config options                                 *"
	@${ECHO}	"*                                                    *"
	@${ECHO}	"* all feedback is welcome, send to:                  *"
	@${ECHO}	"* Michael C. Shultz reso3w83@verizon.net             *"
	@${ECHO}	"******************************************************"
.include <bsd.port.mk>
