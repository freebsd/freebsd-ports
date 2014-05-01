# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	honggfuzz
PORTVERSION=	0.3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	General-purpose fuzzer with simple, command-line interface

LICENSE=	APACHE20
LICENSE_FILE=   ${WRKSRC}/COPYING

USES=	gmake
PORT_OPTIONS=	EXAMPLES

# inplace replacement to remove relative binary path in examples scripts
post-patch:
	${REINPLACE_CMD} -i "" -E "s,\.\./,," ${WRKSRC}/examples/*.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${EXAMPLESDIR})

.include <bsd.port.mk>
