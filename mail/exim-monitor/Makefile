# New ports collection makefile for:	exim-monitor
# Date created:		27 August 2001
# Whom:			sheldonh@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	exim-monitor
PORTVERSION=	${EXIM_VERSION}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/infosys/mail/exim/%SUBDIR%/ \
		ftp://ftp.easynet.be/exim/%SUBDIR%/ \
		ftp://mirror.direct.ca/pub/exim/%SUBDIR%/ \
		ftp://mirror.kn.vutbr.cz/pub/ftp.exim.org/%SUBDIR%/ \
		ftp://sunsite.auc.dk/pub/mail/exim/%SUBDIR%/ \
		ftp://ftp.doc.cs.univ-paris8.fr/mirrors/ftp.exim.org/%SUBDIR%/ \
		ftp://ftp.fu-berlin.de/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.tin.org/pub/mail/exim/%SUBDIR%/ \
		ftp://ftp.freenet.de/pub/ftp.csx.cam.ac.uk/pub/software/email/exim/%SUBDIR%/ \
		ftp://ftp.esat.net/pub/networking/mail/mta/exim/%SUBDIR%/ \
		ftp://nagoya.linux.or.jp/mirror/exim/%SUBDIR%/ \
		http://exim.psshee.com/ftp/%SUBDIR%/ \
		ftp://ftp.nl.uu.net/pub/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.demon.nl/pub/mirrors/exim/%SUBDIR%/ \
		ftp://ftp.easynet.nl/mirror/exim/%SUBDIR%/ \
		ftp://sunsite.uio.no/pub/mail/exim/%SUBDIR%/ \
		http://sunsite.icm.edu.pl/pub/unix/mail/exim/%SUBDIR%/ \
		ftp://ftp.smux.net/pub/exim/%SUBDIR%/ \
		ftp://ftp.is.co.za/networking/mail/mta/exim/%SUBDIR%/ \
		ftp://sunsite.cnlab-switch.ch/mirror/exim/%SUBDIR%/ \
		ftp://ftp.exim.org/pub/exim/%SUBDIR%/ \
		http://www.us.exim.org/ftp/%SUBDIR%/ \
		http://exim.stanford.edu/ftp/pub/exim/%SUBDIR%/ \
		ftp://ftp.fsckit.net/pub/exim/%SUBDIR%/ \
MASTER_SITE_SUBDIR=	exim4
DISTNAME=	exim-${PORTVERSION}
DIST_SUBDIR=	exim

MAINTAINER=	sheldonh@FreeBSD.org
COMMENT=	The Exim monitor for the Exim MTA

USE_BZIP2=	yes
USE_PERL5=	yes
USE_XLIB=	yes

EXIM_VERSION=	4.20

# This dependency is disabled, because it prevents package users from
# using the exim-monitor package with any of the exim slave packages.
#
#RUN_DEPENDS=	${LOCALBASE}/sbin/exim:${PORTSDIR}/mail/exim

MAKE_ENV+=	OSTYPE=${OPSYS} ARCHTYPE=${MACHINE_ARCH}

SEDLIST=	-e 's,XX_PREFIX_XX,${PREFIX},'

do-configure:
	${MKDIR} ${WRKSRC}/Local
	${SED} ${SEDLIST} < ${WRKSRC}/src/EDITME > ${WRKSRC}/Local/Makefile
	${CP} ${WRKSRC}/exim_monitor/EDITME ${WRKSRC}/Local/eximon.conf

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon.bin \
	    ${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/build-${OPSYS}-${MACHINE_ARCH}/eximon \
	    ${PREFIX}/sbin/

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
