# New ports collection makefile for:   R (letter)
# Version required:    R-0.62.2
# Date created:                Tue Jun 23 07:36:55 EST 1998
# Whom:                        Maurice Castro <maurice@serc.rmit.edu.au>
#
# $Id: Makefile,v 1.8 1998/11/20 04:14:58 asami Exp $
#

DISTNAME=	R-0.62.2
PKGNAME=	R-${PAPERSIZE}-0.62.2
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

BROKEN=		package

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_PERL5=	yes

CONFIGURE_ENV=		R_PAPERSIZE=${PAPERSIZE}

PAPERSIZE?=	letter
.if ${PAPERSIZE} != letter && ${PAPERSIZE} != a4
.BEGIN:
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  a4 and letter."
	@${FALSE}
.endif

ALL_TARGET=all help html

MAN1=	R.1 Rdconv.1

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
