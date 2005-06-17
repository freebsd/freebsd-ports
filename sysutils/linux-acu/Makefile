# New ports collection makefile for:	linux-acu
# Date created:		Tue Jun 25 02:24:41 GMT 2002
# Whom:			Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	acu
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	sysutils linux
MASTER_SITES=	# fetch manually
PKGNAMEPREFIX=	linux-
DISTNAME=	Linux-ACU-Driver-v${PORTVERSION}

MAINTAINER=	matt@peterson.org
COMMENT=	Aironet Cisco Utilities for 802.11 wireless NIC's

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the tarball after\
		reading and agreeing to the license at:\
		http://www.cisco.com/pcgi-bin/tablebuild.pl/aironet-utils-linux\
		- once '${DISTNAME}${EXTRACT_SUFX}' has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
USE_X_PREFIX=	yes
NO_WRKSUBDIR=	yes
NO_CDROM=	"Redistribution not allowed"

LINPROCFS!=	/sbin/mount | ${GREP} linprocfs | ${AWK} '{print $1}'

pre-fetch:
.if ${OSVERSION} < 460000
	@${ECHO}
	@${ECHO} "OS-VERSION ${OSVERSION} too low"
	@${ECHO}
	@${ECHO} "acu needs some important sys/dev/an changes"
	@${ECHO} "Please upgrade to 4.6-STABLE or greater"
	@${FALSE}
.endif

post-extract:
.if ${LINPROCFS}
	@${ECHO}
	@${ECHO} "linprocfs is mounted, please umount this filesystem"
	@${ECHO} "becauce acu needs to read ${LINUXBASE}/proc/aironet"
	@${FALSE}
.endif

do-build:
	@${BRANDELF} -t Linux ${WRKSRC}/utilities/acu

do-install:
	@${MKDIR} ${PREFIX}/bin
	@${MKDIR} ${LINUXBASE}/proc/aironet
	@${INSTALL} ${WRKSRC}/utilities/acu ${PREFIX}/bin

post-install:
	@${ECHO} "acu installed under ${PREFIX}/bin"
	@${ECHO} "notes: acu will only run from the root super-user account"
	@${ECHO} "       to allow root access to your X session,"
	@${ECHO} "       run 'xhost localhost' or use sudo."
	@${ECHO} "	acu annoyingly creates"
	@${ECHO} "		/compat/linux/etc/eth?.cfg"
	@${ECHO} "	and will use that over the current card's settings."

.include <bsd.port.post.mk>
