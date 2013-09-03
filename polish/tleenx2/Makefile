# Created by: Maciek Korzen <eaquer@ceti.pl>
# $FreeBSD$

PORTNAME=	tleenx2
PORTVERSION=	20040214
PORTREVISION=	10
CATEGORIES=	polish net
MASTER_SITES=	SF/tleenx/tleenx2/${DISTNAME}
DISTNAME=	TleenX2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Client for polish IM service called Tlen.pl

LIB_DEPENDS=	tlen.1:${PORTSDIR}/polish/libtlen

USES=		pkgconfig
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
USE_XORG=	xscrnsaver
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
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
