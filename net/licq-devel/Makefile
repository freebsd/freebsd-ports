# New ports collection makefile for:    licq
# Version required:                     0.32-a
# Date created:                         2 July 1998
# Whom:                                 Brian Feldman
#
# $Id: Makefile,v 1.1.1.1 1998/07/09 16:01:50 eivind Exp $
#

DISTNAME=	licq-0.32-a
CATEGORIES=	net
MASTER_SITES=	http://pages.infinit.net/fairoff/licq/
EXTRACT_SUFX=	.tgz

MAINTAINER=	brianfeldman@hotmail.com

LIB_DEPENDS=	qt\\.1\\.33:${PORTSDIR}/x11-toolkits/qt133

WRKSRC=		${WRKDIR}/${DISTNAME}

do-install:
		${RM} -rf ${PREFIX}/share/licq
		(cd ${WRKSRC}; make install)
		${INSTALL_PROGRAM} ${PREFIX}/share/licq/licq \
			${PREFIX}/bin/licq-binary
		${RM} ${PREFIX}/share/licq/licq
		${SED} 's|___INSERT_PREFIX_HERE___|PREFIX=${PREFIX}|' \
			< ${FILESDIR}/licq-wrapper \
			> ${PREFIX}/bin/licq
		chmod 555 ${PREFIX}/share/licq ${PREFIX}/bin/licq
.for file in javaToLicq micqToLicq
		chmod 555 ${PREFIX}/share/licq/${file}
.endfor

.include <bsd.port.mk>
