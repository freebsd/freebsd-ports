# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <reso3w83@verizon.net>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.2.7
PORTREVISION=	0
#-----------------------------------------
#for local use, remove before submitting PR
CATEGORIES=		sysutils
#CATEGORIES=		local/sysutils
#VALID_CATEGORIES+=	${CATEGORIES}	# for FreeBSD to accept our local category
#-----------------------------------------
MASTER_SITES=		http://portmanager.sunsite.dk/distfiles/	\
			${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=		ringworm01@gmail.com
COMMENT=		FreeBSD usr/ports status and safe usr/ports update

MAN1=			portmanager.1
MAN3=			libMG.3 		\
			MGdbAdd.3		\
			MGdbCreate.3		\
			MGdbDelete.3		\
			MGdbGetRecordQty.3	\
			MGdbGoTop.3		\
			MGdbSeek.3

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

#
# if --with-bin=something then withvar=${PREFIX} + something
# else defaults to withvar=${PREFIX} + /bin
#
# so --with-bindir=/bin will become ${PREFIX}/bin at configure
# time.
#
CONFIGURE_ARGS=		--with-prefix=${PREFIX} 		\
			--with-bindir=/bin			\
			--with-etcdir=/etc/portmanager		\
			--with-pkgdbdir=/var/db/pkg		\
			--with-portsdir=${PORTSDIR}		\
			--with-sharedir=/share/portmanager	\
			--with-tempdir=/tmp

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--with-debug=yes
.endif

INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
# Need INSTALL_TARGET to install ${PREFIX}/etc/portmanager/pm-020.conf.SAMPLE
INSTALL_TARGET=		install info

post-configure:
	@${REINPLACE_CMD} -e	\
		's|VERSION "${PORTVERSION}"|VERSION "${PORTVERSION}_${PORTREVISION}"|g'	\
		 ${WRKSRC}/externVars.h

post-install:
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"* portmanager                                                         *"
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"*                                                                     *"
.if !defined(WITH_DEBUG)
	@${ECHO}	"* WITH_DEBUG=yes enables debug support and all compile warninings     *"
	@${ECHO}	"*                                                                     *"
.endif
	@${ECHO}	"* upgrade ports example:                                              *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* portmanager -u -ip editors/nedit editors/openoffice                 *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* upgrades everything except nedit,open office and their dependencies *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* portmanager -sl will show you leaf ports, these are safe to remove  *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* portmanager -slid will let you safely remove leaf ports             *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* see man portmanager(1) or http://portmanager.sunsite.dk             *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"* all feedback is welcome, send to:                                   *"
	@${ECHO}	"* Michael C. Shultz ringworm01@gmail.com                              *"
	@${ECHO}	"***********************************************************************"
.include <bsd.port.mk>
