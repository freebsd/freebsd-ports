# New ports collection makefile for:    sma
# Version required:     0.9.13
# Date created:         8 May 1998
# Whom:                 Donald Burr <dburr@FreeBSD.ORG>
#
# $Id: Makefile,v 1.2 1998/05/30 12:36:19 dburr Exp $
#

DISTNAME=	SMA
PKGNAME=	sma-0.9.13
CATEGORIES=	misc
MASTER_SITES=	http://www.scour.net/sma/
EXTRACT_SUFX=	.pl

MAINTAINER=	dburr@FreeBSD.ORG

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PERL5=	yes

do-extract:
	@${MKDIR} ${WRKDIR}

pre-configure:
	@${SED} -e '1,1s:/usr/bin/perl:${PREFIX}/bin/perl5.00404:' \
		-e '/\$debug = 3/s//\$debug = 0/' \
		${DISTDIR}/SMA.pl > ${WRKDIR}/sma

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sma ${PREFIX}/bin

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
