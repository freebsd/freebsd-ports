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

LIB_DEPENDS=	libpaper.so:${PORTSDIR}/print/libpaper

USES=		perl5
USE_PERL5=	build
WRKSRC=		${WRKDIR}/${PORTNAME}
MAKEFILE=	Makefile.unix
MAKE_ENV+=	DATADIR="${DATADIR}" PERL="${PERL5}" CHMOD="${CHMOD}"
SCRIPTS_ENV+=	PERL5=${PERL5} CC=${CC} DATADIR=${DATADIR} \
		MANPREFIX=${MANPREFIX} PAPER=dummy

.include <bsd.port.mk>
