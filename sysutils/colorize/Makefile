# New ports collection makefile for:	colorize
# Date created:				12 June 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	colorize
PORTVERSION=	0.3.4
CATEGORIES=	sysutils
MASTER_SITES=	http://colorize.raszi.hu/downloads/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	petef@FreeBSD.org
COMMENT=	A robust log colorizer

RUN_DEPENDS=	${SITE_PERL}/Term/ANSIColor.pm:${PORTSDIR}/devel/p5-Term-ANSIColor

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

NO_BUILD=	yes
USE_PERL5=	yes

MAN1=		colorize.1
MANCOMPRESSED=	yes

post-patch:
	@${PERL} -pi -e "s|/etc/colorizerc|${PREFIX}/etc/colorizerc|; \
		s|#!/usr/bin/perl|#!${PERL}|g" ${WRKSRC}/colorize

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/colorize ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc.dist
.if !exists(${PREFIX}/etc/colorizerc)
	@${INSTALL_DATA} ${WRKSRC}/colorizerc ${PREFIX}/etc/colorizerc
.endif
	@${INSTALL_MAN} ${WRKSRC}/colorize.1.gz ${PREFIX}/man/man1
	@${SED} -e "s!/usr/local/!${PREFIX}/!" < ${PKGMESSAGE}

.include <bsd.port.mk>
