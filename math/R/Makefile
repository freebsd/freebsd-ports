# New ports collection makefile for:   R
# Version required:    R-0.61.2
# Date created:                Mon May  4 10:03:02 EST 1998
# Whom:                        Maurice Castro <maurice@serc.rmit.edu.au>
#
# $Id$
#

DISTNAME=	R-0.61.2
PKGNAME=	r-${PAPERSIZE:S/A4/a4/:S/LETTER/letter/:S/Letter/letter/}-0.61.2
CATEGORIES=	math
MASTER_SITES=	http://lib.stat.cmu.edu/R/CRAN/src/base/ \
		ftp://ftp.stat.math.ethz.ch/R/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/R/
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

pre-fetch:
.if defined(PAPERSIZE_INVALID)
	@${ECHO} "Invalid value for PAPERSIZE: \"${PAPERSIZE}\""
	@${ECHO} "Possible values are:  A4 (default), and Letter."
	@${FALSE}
.endif

post-configure:
	cd ${WRKSRC}/etc; && ${PREFIX}/bin/perl -pi -e "s#/usr/bin/perl#${PREFIX}/bin/perl#" `grep -l /usr/bin/perl *`

do-install:
	${SED} 's:PREFIX:${PREFIX}:' ${FILESDIR}/R > ${PREFIX}/bin/R
	(cd ${WRKSRC}; find . -type d -exec chmod a+rx \{\} \; )
	(cd ${WRKSRC}; find . -type f -exec chmod a+r \{\} \; )
	chmod a+x ${PREFIX}/bin/R
	${MKDIR} ${PREFIX}/share/R
	${MKDIR} ${PREFIX}/share/R/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/R.binary ${PREFIX}/share/R/bin
	(cd ${WRKSRC}; tar cpf - afm ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - etc ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - html ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - include ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - library ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - demos ) | (cd ${PREFIX}/share/R; tar xpf - )
	(cd ${WRKSRC}; tar cpf - cmd ) | (cd ${PREFIX}/share/R; tar xpf - )

.include <bsd.port.mk>
