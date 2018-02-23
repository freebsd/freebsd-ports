# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	colortail
PORTVERSION=	0.3.3
CATEGORIES=	misc

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	tail(1) replacement with color support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
GNU_CONFIGURE=	yes

GH_ACCOUNT=	joakim666
USE_GITHUB=	yes

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/colortail ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example-conf/conf* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
