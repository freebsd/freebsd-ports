# New ports collection makefile for:    sma
# Version required:     0.9.7
# Date created:         8 May 1998
# Whom:                 Donald Burr <dburr@POBoxes.com>
#
# $Id$
#

DISTNAME=	SMA2
PKGNAME=	sma-0.9.7
CATEGORIES=	misc
MASTER_SITES=	http://www.scour.net/sma/
EXTRACT_SUFX=	.pl

MAINTAINER=	dburr@POBoxes.com

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PERL5=	yes

do-extract:
	@${MKDIR} ${WRKDIR}

pre-configure:
	@${SED} -e '1,1s:/usr/bin/perl:${PREFIX}/bin/perl5.00404:' \
		${DISTDIR}/SMA2.pl > ${WRKDIR}/sma

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sma ${PREFIX}/bin

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
