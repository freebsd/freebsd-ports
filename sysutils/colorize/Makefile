# New ports collection makefile for:	colorize
# Date created:				12 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	colorize
PORTVERSION=	0.3.0
CATEGORIES=	sysutils
MASTER_SITES=	http://nrg.martos.bme.hu/release/colorize/download/gz/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	petef
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		colorize.pl.1

FMT?=	/usr/bin/fmt

post-patch:
	@${PERL} -pi -e "s|/etc/colorizerc|${PREFIX}/etc/colorizerc|; \
		s|#!/usr/bin/perl|#!${PERL}|g" ${WRKSRC}/colorize.pl
	@${GZIP_CMD} -d ${WRKSRC}/colorize.pl.1.gz
	@${PERL} -pi -e 's!colorize.pl!colorize!g' ${WRKSRC}/colorize.pl.1

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/colorize.pl ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc.dist
.if !exists(${PREFIX}/etc/colorizerc)
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc
.endif
	@${INSTALL_MAN} ${WRKSRC}/colorize.pl.1 ${PREFIX}/man/man1/colorize.pl.1
	@${PERL} -pi -e 's,PREFIX,${PREFIX},' ${PKGMESSAGE}
	@${SED} s!/usr/local/!${PREFIX}/! ${PKGMESSAGE} | ${FMT}

.include <bsd.port.mk>
