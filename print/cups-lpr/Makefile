# New ports collection makefile for:   cups-lpr
# Date created:        29 November 2001
# By:                  James Halstead <jah4007@cs.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cups-lpr
PORTVERSION=	${CUPS_VERSION}
CATEGORIES=	print
MAINTAINER=	jah4007@cs.rit.edu

LIB_DEPENDS=	cups.2:${PORTSDIR}/print/cups-base

MAN1=		lp.1 lpoptions.1 lpq.1 lpr.1 lprm.1 lpstat.1 \
		lppasswd.1
MAN8=		accept.8 enable.8 lpadmin.8 lpc.8 lpinfo.8 \
		lpmove.8 cupsaddsmb.8
MLINKS=		accept.8 reject.8
MLINKS+=	enable.8 disable.8
MLINKS+=	lp.1 cancel.1

post-install:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' ${PKGMESSAGE}

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/print/cups/Makefile.inc"
.include <bsd.port.post.mk>
