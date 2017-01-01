# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	honggfuzz
PORTVERSION=	0.7
CATEGORIES=	security

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	General-purpose fuzzer with simple, command-line interface

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	google
GC_TAGNAME=	6d01e82

OPTIONS_DEFINE=	EXAMPLES

# inplace replacement to remove relative binary path in examples scripts
post-patch:
	@${REINPLACE_CMD} -i "" -E "s,\.\./,," ${WRKSRC}/examples/*.sh
	@${REINPLACE_CMD} -i "" -e 's,gcc,${CC},' \
		-e 's| -Werror||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
