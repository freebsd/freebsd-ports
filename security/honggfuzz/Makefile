# New ports collection makefile for:	honggfuzz
# Date created:				2010-12-13
# Whom:					Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	honggfuzz
PORTVERSION=	0.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	sbrabez@gmail.com
COMMENT=	A general-purpose fuzzer with simple, command-line interface

LICENSE=	ASL
LICENSE_FILE=   ${WRKSRC}/COPYING

USE_GMAKE=	yes

# inplace replacement to remove relative binary path in examples scripts
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
