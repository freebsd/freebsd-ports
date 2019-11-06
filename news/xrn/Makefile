# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	xrn
DISTVERSION=	10.00-beta-3
CATEGORIES=	news
MASTER_SITES=	ftp://sipb.mit.edu/pub/xrn/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Usenet News reader for the X Window System

BROKEN=		unfetchable

USES=		bison gmake pkgconfig xorg
GNU_CONFIGURE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

DOCS=		COMMON-PROBLMS COPYRIGHT CREDITS ChangeLog
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -E -e "s|^#error.+||g" \
		-e "s|/usr/lib/sendmail|/usr/sbin/sendmail|g" \
		-e "s|^$$|#define POSIX_REGEX|" \
		${WRKSRC}/config.h

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
