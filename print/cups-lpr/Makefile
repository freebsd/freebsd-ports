# New ports collection makefile for:   cups-lpr
# Date created:        29 November 2001
# By:                  James Halstead <jah4007@cs.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cups-lpr
PORTVERSION=	${VERSION}
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp2.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.easysw.com/pub/cups/${VERSION}/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/internet/printing/cups/${VERSION}/
DISTNAME=	cups-${VERSION}-source

MAINTAINER=	jah4007@cs.rit.edu

VERSION=	1.1.12

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

USE_BZIP2=	yes

WRKSRC=		${WRKDIR}/cups-${VERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --localstatedir=/var

MAN1=		cancel.1 lp.1 lpoptions.1 lpq.1 lpr.1 lprm.1 lpstat.1 \
		lppasswd.1
MAN8=		accept.8 disable.8 enable.8 lpadmin.8 lpc.8 lpinfo.8 \
		lpmove.8 cupsaddsmb.8
MLINKS=		accept.8 reject.8

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.mk>
