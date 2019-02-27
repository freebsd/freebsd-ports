# $FreeBSD$

PORTNAME=	Mcstas-Tools
PORTVERSION=	2.5
CATEGORIES=	science
MASTER_SITES=	http://download.mcstas.org/mcstas-${PORTVERSION}/unix/
PKGNAMEPREFIX=	p5-
DISTFILES=	mcstas-tools-perl-${PORTVERSION}-src.tar.gz \
		mcstas-tools-perl-cmdline-${PORTVERSION}-src.tar.gz

MAINTAINER=	erkn@fysik.dtu.dk
COMMENT=	Perl based tools for the McStas neutron ray tracing package

LICENSE=	GPLv2

RUN_DEPENDS=	mcstas:science/mcstas \
		p5-PGPLOT>=2.21:graphics/p5-PGPLOT \
		p5-Tk>0:x11-toolkits/p5-Tk \
		PDL>0:math/PDL

USES=		cmake perl5 shebangfix

NO_WRKSUBDIR=	yes
CMAKE_ARGS=	-Denable_mcstas=1
SHEBANG_GLOB=	*.pl
PLIST_SUB=	PORTVERSION=${PORTVERSION}

EXECS=		mcdaemon.pl mcdisplay.pl mcdoc.pl mcformatgui.pl mcgui.pl \
		mcplot.pl mcresplot.pl mcrun.pl mcrun.pl mcstas2vitess.pl
WRKSRC_SUBDIRS=	${DISTFILES:S/.tar.gz$//}

do-configure:
.for f in ${WRKSRC_SUBDIRS}
	 @${ECHO_MSG} ${_CMAKE_MSG}
	 ${MKDIR} ${WRKSRC}/${f}/.build
	 @cd ${WRKSRC}/${f}/.build; ${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} ..
.endfor

do-build:
.for f in ${WRKSRC_SUBDIRS}
	 @cd ${WRKSRC}/${f}/.build; ${DO_MAKE_BUILD} ${ALL_TARGET}
.endfor

do-install:
.for f in ${WRKSRC_SUBDIRS}
	@(cd ${WRKSRC}/${f}/.build && ${SETENV} ${MAKE_ENV} ${FAKEROOT} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endfor
.for e in ${EXECS}
	${RLN} ${STAGEDIR}/${PREFIX}/mcstas/${PORTVERSION}/bin/${e} ${STAGEDIR}${PREFIX}/bin/${e}
.endfor

.include <bsd.port.mk>
