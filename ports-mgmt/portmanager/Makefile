# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <reso3w83@verizon.net>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.2.6
PORTREVISION=	1
#-----------------------------------------
#for local use, remove before submitting PR
CATEGORIES=		sysutils
#CATEGORIES=		local/sysutils
#VALID_CATEGORIES+=	${CATEGORIES}	# for FreeBSD to accept our local category
#-----------------------------------------
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=		reso3w83@verizon.net
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

#CONFIGURE_ARGS=
#
#  WITH_DEBUG disbled in 0.2.6, intend to reinstate it
#  in 0.2.7
#.if defined(WITH_DEBUG)
#CONFIGURE_ARGS= 	--with-debug=yes
#.endif

#CONFIGURE_ARGS=		--with-prefix=${PREFIX} 		\
#			--with-bindir=/bin			\
#			--with-etcdir=${PREFIX}/etc/portmanager	\
#			--with-pkgdbdir=${PKG_DBDIR}		\
#			--with-portsdir=${PORTSDIR}		\
#			--with-sharedir=${DATADIR}		\
#			--with-tempdir=/tmp

INSTALLS_SHLIB=		yes
# Need INSTALL_TARGET to install ${PREFIX}/etc/portmanager/pm-020.conf.SAMPLE
INSTALL_TARGET=		install info

post-install:
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"* portmanager                                                         *"
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"*                                                                     *"
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
	@${ECHO}	"* see man portmanager(1) for more information                         *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"* all feedback is welcome, send to:                                   *"
	@${ECHO}	"* Michael C. Shultz reso3w83@verizon.net                              *"
	@${ECHO}	"***********************************************************************"
.include <bsd.port.mk>
