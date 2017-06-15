# Created by: Erik B Knudsen
# $FreeBSD$

PORTNAME=	Mcstas-Tools
PORTVERSION=	2.2a
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/mcstas-${PORTVERSION}/unix/McStas-${PORTVERSION}-UNIX-src/
PKGNAMEPREFIX=	p5-
DISTNAME=	mcstas-tools-perl-${PORTVERSION}-src

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Perl based tools for the McStas neutron ray tracing package

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Tk>0:x11-toolkits/p5-Tk \
		p5-PGPLOT>=2.21:graphics/p5-PGPLOT	\
		PDL>0:math/PDL \
		mcstas:science/mcstas

USES=		cmake perl5 shebangfix
CMAKE_ARGS=	-Denable_mcstas=1
SHEBANG_FILES=	${EXECS:S/$/.pl/}

PLIST_SUB=	PORTVERSION=${PORTVERSION}

EXECS=		mcdaemon mcdisplay mcdoc mcformatgui mcgui mcplot mcresplot mcrun mcstas2vitess

post-install:
	${MV} ${STAGEDIR}${PREFIX}/mcstas/${PORTVERSION}/doc/man/man1/*.1 ${STAGEDIR}${PREFIX}/man/man1/
	${RMDIR} -p ${STAGEDIR}${PREFIX}/mcstas/${PORTVERSION}/doc/man/man1 || : > /dev/null 2>&1
.for target in ${EXECS}
	${LN} -s ${PREFIX}/mcstas/${PORTVERSION}/bin/${target} ${STAGEDIR}${PREFIX}/bin/${target}
.endfor

.include <bsd.port.mk>
