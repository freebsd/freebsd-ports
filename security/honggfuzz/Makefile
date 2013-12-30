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

USE_GMAKE=	yes

# inplace replacement to remove relative binary path in examples scripts
NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -i "" -E "s,\.\./,," ${WRKSRC}/examples/*.sh

do-build:
	@(cd ${WRKSRC}; ${GMAKE})

do-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
