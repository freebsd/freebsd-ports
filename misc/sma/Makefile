# New ports collection makefile for:    sma
# Date created:         8 May 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sma
PORTVERSION=	0.9.13
CATEGORIES=	misc
MASTER_SITES=	http://www.scour.net/sma/
DISTFILES=	SMA.pl

MAINTAINER=	dburr@FreeBSD.org

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

USE_PERL5=	yes

do-extract:
	@${MKDIR} ${WRKDIR}

pre-configure:
	@${SED} -e '1,1s:/usr/bin/perl:${PERL5}:' \
		-e '/\$debug = 3/s//\$debug = 0/' \
		${DISTDIR}/SMA.pl > ${WRKDIR}/sma

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/sma ${PREFIX}/bin

post-install:
	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
