# New ports collection makefile for:   cups
# Date created:        05 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${VERSION}.${REVISION}
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${VERSION}/
DISTNAME=	${PORTNAME}-${VERSION}-${REVISION}-source

MAINTAINER=	greid@ukug.uk.freebsd.org

VERSION=	1.1.6
REVISION=	2

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}

GNU_CONFIGURE=	yes

MAN1=		backend.1 cancel.1 filter.1 lp.1 lpoptions.1 lpq.1 \
		lpr.1 lprm.1 lpstat.1
MAN5=		classes.conf.5 cupsd.conf.5 mime.convs.5 mime.types.5 \
		printers.conf.5
MAN8=		accept.8 cups-lpd.8 cups-polld.8 cupsd.8 disable.8 \
		enable.8 lpadmin.8 lpc.8 lpinfo.8 lpmove.8
MLINKS=		accept.8 reject.8

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
