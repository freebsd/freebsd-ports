# New ports collection makefile for:	LPRng
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	LPRng
PORTVERSION=	3.8.20
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
COMMENT=	An Enhanced Printer Spooler

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	\
		--with-sbindir=${PREFIX}/sbin \
		--with-filterdir=${PREFIX}/libexec/filters \
		--with-lpd_conf_path=${PREFIX}/etc/lpd.conf \
		--with-lpd_perms_path=${PREFIX}/etc/lpd.perms \
		--with-printcap_path=/etc/printcap \
		--enable-gdbm=${LOCALBASE}

MAN1=		cancel.1 lp.1 lpbanner.1 lpf.1 \
		lpq.1 lpr.1 lprm.1 lprng_certs.1 lprng_index_certs.1 \
		lpstat.1 monitor.1 pclbanner.1 psbanner.1
MAN5=		lpd.conf.5 lpd.perms.5 printcap.5
MAN8=		checkpc.8 lpc.8 lpd.8
MANCOMPRESSED=	yes

DOC_FILES=	CHANGES LPRng-HOWTO.* *.jpg LISA98.ppt
HTML_FILES=	LPRng.jpg LPRngT-L.jpg LPRngT-S.jpg chooser.png clients.png \
		configfiles.png filter.png index.html network.png parallel.png \
		pooling.png printserver.png samba.png serial.png spooler.png \
		x_add.png x_advanced.png x_checkpc.png x_edit.png \
		x_ifhpfilter.png x_nup.png x_open.png x_printcaps.png \
		x_reread.png x_results.png x_smb.png x_write.png
OTHER_FILES=	Cookbook.pdf

post-install:
	@${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0555 ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/HTML
	@${MKDIR} ${DOCSDIR}/PDF
	@${INSTALL_DATA} ${WRKSRC}/PrintingCookbook/PDF/${OTHER_FILES} ${DOCSDIR}/PDF
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/HOWTO/${file} ${DOCSDIR}
.endfor
.for file in ${HTML_FILES}
	@${INSTALL_DATA} ${WRKSRC}/PrintingCookbook/HTML/${file} ${DOCSDIR}/HTML
.endfor
	@${CAT} ${PKGMESSAGE} | ${SED} -e "s|@@PREFIX@@|${PREFIX}|g"

.include <bsd.port.mk>
