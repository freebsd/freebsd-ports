# New ports collection makefile for:   R
# Version required:    R-0.62.2
# Date created:                Tue Jun 23 07:36:55 EST 1998
# Whom:                        Maurice Castro <maurice@serc.rmit.edu.au>
#
# $Id: Makefile,v 1.4 1998/07/02 06:27:40 asami Exp $
#

DISTNAME=	R-0.62.2
PKGNAME=	R-${PAPERSIZE:S/A4/a4/:S/LETTER/letter/:S/Letter/letter/}-0.62.2
CATEGORIES=	math
MASTER_SITES=	http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.biostat.washington.edu/mirrors/R/CRAN/src/base/ \
		http://cran.stat.wisc.edu/src/base/ \
		ftp://ftp.ci.tuwien.ac.at/R/src/base/ \
		http://SunSITE.auc.dk/R/src/base/ \
		http://www.stat.unipg.it/pub/stat/statlib/R/CRAN/src/base/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/CRAN/src/base/ \
		ftp://dola.snu.ac.kr/pub/R/CRAN/src/base/ \
		http://www.stat.math.ethz.ch/R-CRAN/src/base/
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

MAN1=	R.1 Rdconv.1

pre-fetch:
.if defined(PAPERSIZE_INVALID)
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default), and Letter."
	@${FALSE}
.endif

test:
	@(cd ${WRKSRC}; make test-All)

do-install:
	${INSTALL_MAN} ${WRKSRC}/R.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/Rdconv.1 ${PREFIX}/man/man1
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
