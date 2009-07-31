# New ports collection makefile for:	g3data
# Date created:		2006-09-15
# Whom:			trasz <trasz@pin.if.uz.zgora.pl>
#
# $FreeBSD$
#

PORTNAME=	g3data
PORTVERSION=	1.5.3
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.frantz.fi/software/

MAINTAINER=	trasz@FreeBSD.org
COMMENT=	Utility for extracting data from graphs

BUILD_DEPENDS=	nsgmls:${PORTSDIR}/textproc/jade \
		${LOCALBASE}/share/sgml/docbook/utils-0.6.14/helpers/docbook2man-spec.pl:${PORTSDIR}/textproc/docbook-utils \
		${LOCALBASE}/share/sgml/docbook/4.1/docbook.dtd:${PORTSDIR}/textproc/docbook-410

USE_GNOME=	gtk20
ALL_TARGET=
MAN1=		g3data.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/g3data %%EXAMPLESDIR%%/test1.png %%EXAMPLESDIR%%/test1.values \
		%%EXAMPLESDIR%%/test2.png %%EXAMPLESDIR%%/test2.values
PLIST_DIRS=	%%EXAMPLESDIR%%

post-install:
		@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/test1.png ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/test1.values ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/test2.png ${EXAMPLESDIR}
		${INSTALL_DATA} ${WRKSRC}/test2.values ${EXAMPLESDIR}

.include <bsd.port.mk>
