# Created by: thierry@pompo.net

PORTNAME=	gf2x
PORTVERSION=	1.3.0
CATEGORIES=	math

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Library for multiplying polynomials over the binary field

LICENSE=		GPLv3 LGPL21
LICENSE_COMB=		dual
LICENSE_FILE_LGPL21=	${WRKSRC}/COPYING.LIB
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr/
GL_COMMIT=	27ba588f03bf6e1e74763903bab25e6e8bb6d0f0

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

TEST_TARGET=	check

OPTIONS_RADIO=		LIC
OPTIONS_RADIO_LIC=	LIC_GPLV3 LIC_LGPL21
OPTIONS_DEFAULT=	LIC_GPLV3
LIC_GPLV3_DESC=		Choose the GPLv3 version
LIC_LGPL21_DESC=	Choose the LGPL 2.1 version

.include <bsd.port.options.mk>

post-extract:
.if ${PORT_OPTIONS:MLIC_LGPL21}
	${MV} ${WRKSRC}/toom-gpl.c ${WRKSRC}/toom-gpl.c.GPLv3
	${MV} ${WRKSRC}/toom-gpl-placeholder.c ${WRKSRC}/toom-gpl.c
.endif

.include <bsd.port.mk>
