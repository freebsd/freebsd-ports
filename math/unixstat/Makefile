# New ports collection makefile for:   stat
# Date created:        23 August 2001
# Whom:                mwm
#
# $FreeBSD$
#

PORTNAME=	unixstat
PORTVERSION=	5.4
CATEGORIES=	math
MASTER_SITES=	# must fetch manually
DISTNAME=	stat
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mwm@mired.org

NO_PACKAGE=	"License does not allow redistribution of binaries"
RESTRICTED=	"Gary Pearlman requires that users agree to his license to \
		get the dist file"

MAN1=		abut.1 anova.1 calc.1 colex.1 contab.1 desc.1 dm.1 dprime.1 \
		dsort.1 features.1 ff.1 fls.1 fpack.1 linex.1 maketrix.1 \
		manstat.1 oneway.1 pair.1 perm.1 probdist.1 rankind.1 \
		rankrel.1 ranksort.1 regress.1 repeat.1 reverse.1 series.1 \
		stats.1 transpose.1 ts.1 unixstat.1 validata.1

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} ]; then \
	  ${ECHO} ""; \
	  ${ECHO} "Gary Perlman requires that users agree to his license"; \
	  ${ECHO} "before he will allow access to the dist file."; \
	  ${ECHO} "See his web site at http://www.acm.org/~perlman/stat/ for"; \
	  ${ECHO} "details.  Then put ${DISTNAME}${EXTRACT_SUFX} in"; \
	  ${ECHO} "${DISTDIR} and run make again."; \
	  ${ECHO} ""; \
	  exit 1;\
	fi

post-patch:
	@mv ${WRKSRC}/man/intro.1 ${WRKSRC}/man/unixstat.1
	@rm ${WRKSRC}/man/cat.1

do-build:
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} make ${MAKE_ARGS})

do-install:
	@strip ${WRKSRC}/bin/*
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${PREFIX}/man/man1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/handbook/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
