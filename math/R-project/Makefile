# New ports collection makefile for:   R
# Version required:    R-0.62.1
# Date created:                Tue Jun 23 07:36:55 EST 1998
# Whom:                        Maurice Castro <maurice@serc.rmit.edu.au>
#
# $Id: Makefile,v 1.2 1998/05/07 06:08:24 mph Exp $
#

DISTNAME=	R-0.62.1
PKGNAME=	R-${PAPERSIZE:S/A4/a4/:S/LETTER/letter/:S/Letter/letter/}-0.62.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.ci.tuwien.ac.at/pub/R/src/base/ \
		ftp://SunSITE.auc.dk/pub/languages/R/src/base/ \
		http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://ftp.stat.math.ethz.ch/R-CRAN/src/base/ \
		http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/base/ \
		ftp://franz.stat.wisc.edu/pub/R/src/base/
EXTRACT_SUFX=	.tgz

MAINTAINER=	maurice@serc.rmit.edu.au

GNU_CONFIGURE=	yes
USE_PERL5=	yes

MANUAL_PACKAGE_BUILD=	PAPERSIZE has to be set to Letter A4
CONFIGURE_ENV=		R_PAPERSIZE=${PAPERSIZE}

.if !defined(PAPERSIZE)
PAPERSIZE=a4
.elif ${PAPERSIZE} == LETTER || ${PAPERSIZE} == Letter
PAPERSIZE=letter
.elif ${PAPERSIZE} == A4
PAPERSIZE=a4
.elif ${PAPERSIZE} != a4 && ${PAPERSIZE} != letter
PAPERSIZE_INVALID=yes
.endif

ALL_TARGET=all help html

pre-fetch:
.if defined(PAPERSIZE_INVALID)
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default), and Letter."
	@${FALSE}
.endif

do-install:
	-gzip ${WRKSRC}/R.1
	-gzip ${WRKSRC}/Rdconv.1
	${INSTALL_DATA} ${WRKSRC}/R.1.gz ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/Rdconv.1.gz ${PREFIX}/man/man1
	${SED} 's:PREFIX:${PREFIX}:;s:DEFAULTPAPER:${PAPERSIZE}:' ${FILESDIR}/R > ${PREFIX}/bin/R
	(cd ${WRKSRC}; find . -type d -exec chmod a+rx \{\} \; )
	(cd ${WRKSRC}; find . -type f -exec chmod a+r \{\} \; )
	chmod a+x ${PREFIX}/bin/R
	${MKDIR} ${PREFIX}/share/R
	${MKDIR} ${PREFIX}/share/R/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/R.binary ${PREFIX}/share/R/bin
	(cd ${WRKSRC}; tar cpf - afm ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - etc ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - doc ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - include ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - library ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - demos ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - cmd ) | (cd ${PREFIX}/share/R; tar xpf - )

.include <bsd.port.mk>
