# New ports collection makefile for:	bugs
# Version required:	1.8.1
# Date created:		20 June 1998
# Whom:			Stephane Legrand
#
# $Id$
#

DISTNAME=		bugs-1.8.1
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_SUNSITE} \
			http://www.asi.fr/~martinez/crypto/
MASTER_SITE_SUBDIR=	apps/crypto

MAINTAINER=		stephane@lituus.fr

USE_GMAKE=		yes

# No Manual page

# Cryptography = be extra careful...
NO_CDROM=	may contain export-restricted material
NO_PACKAGE=	may contain export-restricted material
RESTRICTED=	Cryptography

post-configure:
	(cd ${WRKSRC}; ${MAKE} bsd)
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.pre_sed
	${SED} -e 's:^INSTALL_PATH = "/usr/local/bugs-.*":INSTALL_PATH = "${PREFIX}/${DISTNAME}":' \
		-e 's/^install: instchoice all/install: instchoice/' \
		< ${WRKSRC}/Makefile.pre_sed > ${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/${DISTNAME}
.endif
	${CP} -R ${WRKSRC}/include ${PREFIX}/${DISTNAME}
	strip ${PREFIX}/${DISTNAME}/bcrypt \
		${PREFIX}/${DISTNAME}/bhide \
		${PREFIX}/${DISTNAME}/bkey \
		${PREFIX}/${DISTNAME}/blogin \
		${PREFIX}/${DISTNAME}/bpass \
		${PREFIX}/${DISTNAME}/bpassdel \

.include <bsd.port.mk>
