# New ports collection makefile for:	lyx
# Version required:	1.0.4
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

DISTNAME=	lyx-1.0.4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/ \
		ftp://alpha.tat.physik.uni-tuebingen.de/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms \
		Xpm.4:${PORTSDIR}/graphics/xpm

USE_PERL5=	yes
GNU_CONFIGURE=	yes
STRIP=
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11 ${LOCALBASE}/include"
MAN1=		lyx.1 reLyX.1

.if !defined(WITH_ISPELL)
pre-fetch:
	@${ECHO_MSG} "If you want this port built with spell checker support, use"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

.include <bsd.port.mk>
