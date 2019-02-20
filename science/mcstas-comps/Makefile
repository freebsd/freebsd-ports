# Created by: Erik B Knudsen
# $FreeBSD$

PORTNAME=	mcstas-comps
PORTVERSION=	2.5
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/${PORTNAME:C/-comps\$//}-${PORTVERSION}/unix/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Component Library for the McStas neutron ray tracing package

LICENSE=	GPLv2

RUN_DEPENDS=	mcstas:science/mcstas

USES=		cmake:noninja fortran shebangfix

SHEBANG_FILES=	samples/sasview_generator.py
PLIST_SUB=	PORTVERSION=${PORTVERSION}

MCEXECS=	cif2hkl mcpl2ssw mcpltool ssw2mcpl

post-install:
.for e in ${MCEXECS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/mcstas/${PORTVERSION}/bin/${e}
	${RLN} ${STAGEDIR}${PREFIX}/mcstas/${PORTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
