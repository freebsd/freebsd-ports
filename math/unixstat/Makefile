# New ports collection makefile for:   stat
# Date created:        23 August 2001
# Whom:                mwm
#
# $FreeBSD$
#

PORTNAME=	unixstat
PORTVERSION=	5.4
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	# must fetch manually
DISTNAME=	stat
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	mwm@mired.org
COMMENT=	A statistics package designed for use with the Unix shell

RESTRICTED=	"License does not allow redistribution of binaries"

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} < 500000 )
EXTRACT_DEPENDS=gtar:${PORTSDIR}/archivers/gtar
TAR=		gtar
.endif

EXTRACT_CMD=	uncompress
EXTRACT_BEFORE_ARGS=-c
EXTRACT_AFTER_ARGS=| ${TAR} -xf -

MAN1=		abut.1 anova.1 calc.1 colex.1 contab.1 desc.1 dm.1 dprime.1 \
		dsort.1 features.1 ff.1 fls.1 fpack.1 linex.1 maketrix.1 \
		manstat.1 oneway.1 pair.1 perm.1 probdist.1 rankind.1 \
		rankrel.1 ranksort.1 regress.1 repeat.1 reverse.1 series.1 \
		stats.1 transpose.1 ts.1 unixstat.1 validata.1

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
IGNORE="Gary Perlman requires that users agree to his license"\
"before he will allow access to the distfile."\
"See his web site at http://www.acm.org/~perlman/stat/ for"\
"details.  Then put ${DISTNAME}${EXTRACT_SUFX} in"\
"${DISTDIR} and run make again"
.endif

post-patch:
	@${MV} ${WRKSRC}/man/intro.1 ${WRKSRC}/man/unixstat.1
	@${RM} ${WRKSRC}/man/cat.1

do-build:
	@(cd ${WRKSRC}/src; ${SETENV} ${MAKE_ENV} make ${MAKE_ARGS})

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/* ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/man/*.1 ${PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/handbook/* ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
