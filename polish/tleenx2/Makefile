# New ports collection makefile for:	tleenx2
# Date created:		25 September 2003
# Whom:			Maciek Korzen <eaquer@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	tleenx2
PORTVERSION=	20040214
PORTREVISION=	7
CATEGORIES=	polish net
MASTER_SITES=	SF/tleenx/tleenx2/${DISTNAME}
DISTNAME=	TleenX2-${PORTVERSION}

MAINTAINER=	mkorzen@gmail.com
COMMENT=	Client for polish IM service called Tlen.pl

LIB_DEPENDS=	tlen.1:${PORTSDIR}/polish/libtlen

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_XORG=	xscrnsaver
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/TleenX2-${PORTVERSION}

MAN1=		tleenx2.1
PORTDOCS=	README gg.txt sms.txt

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/X11R6,${LOCALBASE},g' ${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
