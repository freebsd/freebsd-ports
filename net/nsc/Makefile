# ports collection makefile for:	nsc
# Date created:			Tue Apr  3 14:25:48 CEST 2001
# Whom:				Dirk Froemberg <dirk@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nsc
PORTVERSION=	0.52
CATEGORIES=	net
MASTER_SITES=	http://dev.null.dk/~goth/nsc/ \
		http://meridian-enviro.com/rand/

MAINTAINER=	dirk@FreeBSD.org
COMMENT=	Netsaint Console monitor

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Curses.pm:${PORTSDIR}/devel/p5-Curses

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/nsc

do-install:
	${PERL} -i -pe 's|%%PREFIX%%|${PREFIX}|g; s|%%PERL%%|${PERL}|g' ${WRKSRC}/nsc.pl
	${INSTALL_SCRIPT} ${WRKSRC}/nsc.pl ${PREFIX}/bin/nsc

.include <bsd.port.mk>
