# New ports collection makefile for:    yodl
# Date created:         22 Oct 1997
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yodl
PORTVERSION=	1.22
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.sco.com/skunkware/src/textproc/ \
		ftp://ftp.sunsite.org.uk/Mirrors/ftp.sco.com/skunkware/src/textproc/ \
		ftp://ftp.vse.cz/pub/.sd10c/SCO/ftp.sco.com/skunkware/src/textproc/ \
		ftp://ftp.netsw.org/netsw/Typesetting/ASCII/Generate/ \
		ftp://ftp.win.ne.jp/pub/misc/ \
		ftp://ftp.eos.hokudai.ac.jp/pub/misc/ \
		ftp://ftp.sunet.se/pub3/vendor/sco/skunkware/src/textproc/

MAINTAINER=	dburr@FreeBSD.org

BUILD_DEPENDS=	latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips
RUN_DEPENDS=	latex:${PORTSDIR}/print/latex \
		dvips:${PORTSDIR}/print/dvips

ALL_TARGET=	progs manpages misc/striproff
INSTALL_TARGET=	installman installmanual

MAN1=		yodl.1 \
		striproff.1 \
		yodlconverters.1
MAN5=		yodl.5
MAN7=		yodlmacros.7 \
		yodlmanpage.7

do-build:
	(cd ${WRKSRC} && ${SETENV} CFLAGS="${CFLAGS}" ${GMAKE} PREFIX=${PREFIX} progs)
	(cd ${WRKSRC}/misc && gcc ${CFLAGS} -s -o striproff striproff.c)

post-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/misc/striproff ${PREFIX}/bin

.include <bsd.port.mk>
