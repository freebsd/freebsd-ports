# New ports collection makefile for:   cups
# Date created:        05 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${VERSION}#.${REVISION}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${VERSION}/
DISTNAME=	${PORTNAME}-${VERSION}-source

MAINTAINER=	jah4007@cs.rit.edu

VERSION=	1.1.12

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --localstatedir=/var

MAN1=		backend.1 cancel.1 filter.1 lp.1 lpoptions.1 lpq.1 \
		lpr.1 lprm.1 lpstat.1 lppasswd.1
MAN3=		cups-config.3
MAN5=		classes.conf.5 cupsd.conf.5 mime.convs.5 mime.types.5 \
		printers.conf.5
MAN8=		accept.8 cups-lpd.8 cups-polld.8 cupsd.8 disable.8 \
		enable.8 lpadmin.8 lpc.8 lpinfo.8 lpmove.8 \
		cupsaddsmb.8
MLINKS=		accept.8 reject.8

post-install:
	@${INSTALL_DATA} ${WRKSRC}/conf/classes.conf \
		${PREFIX}/etc/cups/classes.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/client.conf \
		${PREFIX}/etc/cups/client.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/cupsd.conf \
		${PREFIX}/etc/cups/cupsd.conf.sample
	@${INSTALL_DATA} ${WRKSRC}/conf/printers.conf \
		${PREFIX}/etc/cups/printers.conf.sample
	@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/cups.sh \
		${PREFIX}/etc/rc.d/cupsd.sh.sample
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
