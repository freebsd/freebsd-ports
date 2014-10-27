# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colortail
PORTVERSION=	0.3.3
CATEGORIES=	misc
MASTER_SITES=	http://joakimandersson.se/files/

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	tail(1) replacement with color support

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colortail ${STAGEDIR}${PREFIX}/bin

	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
