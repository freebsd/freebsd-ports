# New ports collection makefile for:	lyx
# Date created:		Sa  12 Okt 1996 19:20:51 MET DST
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.1.6.4
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/
DISTNAME=	lyx-1.1.6

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	patch-1.1.6fix1.gz patch-1.1.6fix2.gz patch-1.1.6fix3.gz \
		patch-1.1.6fix4.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	dirk@FreeBSD.org

BUILD_DEPENDS=	latex:${PORTSDIR}/print/teTeX
RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX
.if defined(WITH_ISPELL)
RUN_DEPENDS+=	ispell:${PORTSDIR}/textproc/ispell
.endif
LIB_DEPENDS=	forms.0:${PORTSDIR}/x11-toolkits/xforms \
		intl.1:${PORTSDIR}/devel/gettext

USE_GMAKE=	yes
USE_AUTOCONF=	yes
USE_XPM=	yes
USE_NEWGCC=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-extra-lib="${X11BASE}/lib ${LOCALBASE}/lib" \
		--with-extra-inc="${X11BASE}/include ${LOCALBASE}/include"
MAN1=		lyx.1 reLyX.1

.if !defined(WITH_ISPELL)
pre-fetch:
	@${ECHO_MSG} "If you want this port built with spell checker support, use"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

post-patch:
	(cd ${WRKSRC}; ${TOUCH} Makefile.in */Makefile.in src/config.h.in)
	(cd ${WRKSRC}/lib/doc; ${RM} -f *.orig)

.include <bsd.port.mk>
