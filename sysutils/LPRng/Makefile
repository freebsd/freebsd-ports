# New ports collection makefile for:	LPRng
# Version required:	3.5.1
# Date created:		2 Apr 1997
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.3 1998/01/22 08:19:36 fenner Exp $
#

DISTNAME=	LPRng-3.5.1
CATEGORIES=	sysutils print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz
EXTRA_FILES=	LPRng_DOC-3.5.1.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${EXTRA_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	desmo@bandwidth.org

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lpddir=/usr/local/sbin

post-install:
	(cd ${WRKSRC} ; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} default)
	@cat ${FILESDIR}/lprng.sh | \
		${SED} -e "s|@@PREFIX@@|${PREFIX}|g" > ${PREFIX}/etc/rc.d/lprng.sh
	@chmod +x ${PREFIX}/etc/rc.d/lprng.sh
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/LPRng
	@for file in ${EXTRA_FILES}; do \
		cp ${DISTDIR}/$$file ${PREFIX}/share/doc/LPRng; \
		cd ${PREFIX}/share/doc/LPRng; \
		tar xvfz $$file; \
		rm ${PREFIX}/share/doc/LPRng/$$file; \
	done
	@cat ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
