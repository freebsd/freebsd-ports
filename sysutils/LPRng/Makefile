# New ports collection makefile for:	LPRng
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	LPRng
PORTVERSION=	3.8.10
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.lprng.com/pub/%SUBDIR%/ \
		ftp://ftp.astart.com/pub/%SUBDIR%/ \
		ftp://ftp.cise.ufl.edu/pub/mirrors/%SUBDIR%/ \
		ftp://ftp.cs.umn.edu/pub/%SUBDIR%/ \
		ftp://ftp.sage-au.org.au/pub/printing/spooler/lprng/LPRng/ \
		ftp://ftp.informatik.uni-hamburg.de/pub/os/unix/utils/%SUBDIR%/ \
		ftp://ftp.uni-paderborn.de/pub/unix/printer/%SUBDIR%/
MASTER_SITE_SUBDIR=	LPRng/LPRng
EXTRACT_SUFX=	.tgz

MAINTAINER=	papowell@astart.com

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	\
		--with-sbindir=${PREFIX}/sbin \
		--with-filterdir=${PREFIX}/libexec/filters \
		--with-lpd_conf_path=${PREFIX}/etc/lpd.conf \
		--with-lpd_perms_path=${PREFIX}/etc/lpd.perms \
		--with-printcap_path=/etc/printcap \
		--enable-gdbm=${LOCALBASE}
USE_LIBTOOL=	yes

MAN1=		cancel.1 lp.1 lpbanner.1 lpf.1 \
		lpq.1 lpr.1 lprm.1 lpstat.1 monitor.1 \
		pclbanner.1 psbanner.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpc.8 lpd.8
MANCOMPRESSED=	yes

DOC_FILES=	CHANGES LPRng-HOWTO.* *.jpg LISA98.ppt

post-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0555 ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/HOWTO/${file} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s|@@PREFIX@@|${PREFIX}|g"

.include <bsd.port.mk>
