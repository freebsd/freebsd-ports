# New ports collection makefile for:	bugs
# Date created:		20 June 1998
# Whom:			Stephane Legrand
#
# $FreeBSD$
#

PORTNAME=		bugs
PORTVERSION=		4.0.1
CATEGORIES=		security
MASTER_SITES=		http://www.bcrypt.com/english/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		stephane.legrand@bigfoot.com

PLIST_SUB+=		PORTVERSION=${PORTVERSION}

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

post-build:
	${CP} ${WRKSRC}/lib/unix/*.a ${WRKSRC}/lib/

pre-install:
	(cd ${WRKSRC}; ${MAKE} test)

post-install:
.if !defined(NOPORTDOCS)
	${CP} -R ${WRKSRC}/doc ${PREFIX}/${DISTNAME}
.endif
	${CP} -R ${WRKSRC}/include ${PREFIX}/${DISTNAME}
	strip ${PREFIX}/${DISTNAME}/bchat \
		${PREFIX}/${DISTNAME}/bcrypt \
		${PREFIX}/${DISTNAME}/bhide \
		${PREFIX}/${DISTNAME}/bkey \
		${PREFIX}/${DISTNAME}/block \
		${PREFIX}/${DISTNAME}/blogin \
		${PREFIX}/${DISTNAME}/bmore \
		${PREFIX}/${DISTNAME}/bpass \
		${PREFIX}/${DISTNAME}/bpassdel \
		${PREFIX}/${DISTNAME}/bunlock \

.include <bsd.port.mk>
