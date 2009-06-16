# New ports collection makefile for:	xrn
# Date created:		13 September 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xrn
DISTVERSION=	10.00-beta-1
CATEGORIES=	news
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	johans@stack.nl
COMMENT=	Usenet News reader for the X Window System

MAN1=		xrn.1
MANCOMPRESSED=	no
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

DOCS=		COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -E -e "s|^#error.+||g" \
		-e "s|/usr/lib/sendmail|/usr/sbin/sendmail|g" \
		-e "s|^$$|#define POSIX_REGEX|" \
		${WRKSRC}/config.h

post-install:
.ifndef		NOPORTDOCS
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
