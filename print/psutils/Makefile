# Created by: Jean-Marc Zucconi <jmz@FreeBSD.org> and David O'Brien <obrien@FreeBSD.org>
# $FreeBSD$

PORTNAME=	psutils
PORTVERSION=	1.17
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.dcs.ed.ac.uk/pub/ajcd/ \
		ftp://ftp.knackered.org/pub/psutils/ \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/psutils
DISTNAME=	psutils-p17

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Utilities for manipulating PostScript documents

LIB_DEPENDS=	paper:${PORTSDIR}/print/libpaper

USES=		perl5
USE_PERL5=	build
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.unix
MAKE_ENV+=	DATADIR="${DATADIR}" PERL="${PERL5}" CHMOD="${CHMOD}"
MAN1=		psbook.1 psselect.1 pstops.1 epsffit.1 psnup.1 psresize.1 \
		getafm.1 fixdlsrps.1 fixfmps.1 fixmacps.1 fixpsditps.1 \
		fixpspps.1 fixtpps.1 fixwfwps.1 fixwpps.1 fixwwps.1 \
		extractres.1 includeres.1 fixscribeps.1 psmerge.1
SCRIPTS_ENV+=	PERL5=${PERL5} CC=${CC} DATADIR=${DATADIR} \
		MANPREFIX=${MANPREFIX} PAPER=dummy

.include <bsd.port.mk>
