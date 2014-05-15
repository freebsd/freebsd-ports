# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlada
PORTVERSION=	4.4.2.0
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/
DISTNAME=	xmlada-gpl-${YEAR}-src

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore XML suite for the Ada language

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		ada gmake
YEAR=		2014
NO_MTREE=	yes
MAKE_ARGS+=	PROCESSORS=${MAKE_JOBS_NUMBER}
WRKSRC=		${WRKDIR}/xmlada-${YEAR}-src

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	sphinx-build:${PORTSDIR}/textproc/py-sphinx
.endif

# Link options were added for sax, dom, schema, and input_sources libraries
# "-R" option disables all rpaths except adalib and compiler libs.  This is
#      done because by default the rpaths will points at the WRKOBJDIR because
#      it doesn't support the concept of DESTDIR.
# "-Wl,-R" adds a second rpath string.
# -Wl,-rpath is a better choice, but synonym -Wl,-R works on all BSD and SunOS

post-patch:
	@${REINPLACE_CMD} -e "s,@ADDITIONAL_RPATH@,${LOCALBASE}/lib," \
	  ${WRKSRC}/sax/sax.gpr \
	  ${WRKSRC}/dom/dom.gpr \
	  ${WRKSRC}/schema/schema.gpr \
	  ${WRKSRC}/input_sources/input_sources.gpr
.if ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e 's/^all: \(.*\)/all: \1 docs/g' ${WRKSRC}/Makefile.in
.endif

do-build:
	# Override build target to avoid -jX getting passed to makefile
	# Parallel builds are handled with PROCESSORS setting
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/xmlada/_sources

.include <bsd.port.mk>
