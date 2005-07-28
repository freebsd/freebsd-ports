# New ports collection makefile for:	portmanager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <reso3w83@verizon.net>
#
# $FreeBSD$
#

PORTNAME=	portmanager
PORTVERSION=	0.2.9
PORTREVISION=	5
#-----------------------------------------
#for local use, remove before submitting PR
CATEGORIES=		sysutils
#CATEGORIES=		local/sysutils
#VALID_CATEGORIES+=	${CATEGORIES}	# for FreeBSD to accept our local category
#-----------------------------------------
MASTER_SITES=		http://portmanager.sunsite.dk/distfiles/	\
			${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=		ports@FreeBSD.org
COMMENT=		FreeBSD installed ports status and safe update utility

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
INSTALL_TARGET=		install info

pre-fetch:
.if !defined(WITH_DEBUG)
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"* portmanager                                                         *"
	@${ECHO}	"***********************************************************************"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"* WITH_DEBUG=yes enables debug support and all compile warnings       *"
	@${ECHO}	"*                                                                     *"
	@${ECHO}	"***********************************************************************"
.endif

post-configure:
	@${REINPLACE_CMD} -e	\
		's|VERSION "${PORTVERSION}"|VERSION "${PORTVERSION}_${PORTREVISION}"|g'	\
		 ${WRKSRC}/externVars.h

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
