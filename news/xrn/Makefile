# New ports collection makefile for:	xrn
# Date created:		13 September 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xrn
PORTVERSION=	9.02
PORTREVISION=	2
CATEGORIES=	news
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Usenet News reader for the X Window System

USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAN1=		xrn.1
MANCOMPRESSED=	no

DOCS=		COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog

post-patch:
	@${REINPLACE_CMD} -E -e "s|^#error.+||g; \
		s|/usr/lib/sendmail|/usr/sbin/sendmail|g;" ${WRKSRC}/config.h

do-install:
	${INSTALL_MAN} ${WRKSRC}/xrn.man ${PREFIX}/man/man1/xrn.1
	${INSTALL_PROGRAM} ${WRKSRC}/xrn ${PREFIX}/bin/
	${INSTALL_DATA}	${WRKSRC}/XRn.ad ${PREFIX}/lib/X11/app-defaults/XRn
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
