# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	honggfuzz
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	General-purpose fuzzer with simple, command-line interface

LICENSE=	APACHE20

USES=	gmake tar:tgz
OPTIONS_DEFINE=	EXAMPLES

# inplace replacement to remove relative binary path in examples scripts
post-patch:
	${REINPLACE_CMD} -i "" -E "s,\.\./,," ${WRKSRC}/examples/*.sh
	${REINPLACE_CMD} -i "" -e 's,gcc,${CC},' \
		-e 's| -Werror||' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
