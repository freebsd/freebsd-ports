# New ports collection makefile for:	tleenx2
# Date created:		25 September 2003
# Whom:			Maciek Korzen <eaquer@ceti.pl>
#
# $FreeBSD$
#

PORTNAME=	tleenx2
PORTVERSION=	20040214
PORTREVISION=	2
CATEGORIES=	polish net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	tleenx
DISTNAME=	TleenX2-${PORTVERSION}

MAINTAINER=	eaquer@ceti.pl
COMMENT=	Client for polish IM service called Tlen.pl

LIB_DEPENDS=	tlen.1:${PORTSDIR}/polish/libtlen

USE_GNOME=	gtk20
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
WRKSRC=		${WRKDIR}/TleenX2-${PORTVERSION}

MAN1=		tleenx2.1
PORTDOCS=	README gg.txt sms.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
