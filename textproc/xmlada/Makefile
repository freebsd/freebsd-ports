# Created by: John Marino <marino@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xmlada
PORTVERSION=	4.4.0.0
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://downloads.dragonlace.net/src/

MAINTAINER=	marino@FreeBSD.org
COMMENT=	Adacore XML suite for the Ada language

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USES=		ada gmake
NO_MTREE=	yes

MAKE_JOBS_UNSAFE=	yes
NO_LICENSES_INSTALL=	yes

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

post-install:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/doc/xmlada/_sources
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * \( -type f -or -type l \) | \
	   ${SORT} > ${TMPPLIST}
	@cd ${STAGEDIR}${PREFIX}; ${FIND} * -type d | ${AWK} '/\//' | ${SORT} -r | \
	   ${SED} -e '/lib\/gnat$$/d' -e '/share\/doc$$/d' -e '/share\/gps/d' \
	   -e 's/^/@dirrm /g' >> ${TMPPLIST}
	@echo "@unexec rmdir %D/lib/gnat 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps/plug-ins 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/gps 2>/dev/null || true" >> ${TMPPLIST}
	@echo "@unexec rmdir %D/share/doc 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.mk>
