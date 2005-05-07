# New ports collection makefile for:	yadda
# Date created:		2004-01-01
# Whom:			Jesper Noehr <jesper@noehr.org>
#
# $FreeBSD$
#

PORTNAME=	yadda
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.printf.dk/projects/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another Damn Delivery Agent

RUN_DEPENDS=	${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit

USE_PERL5_RUN=	yes

do-build:
	${SED} -e '1s,/usr/bin/perl,${PERL},' ${WRKSRC}/yadda \
		> ${WRKDIR}/yadda

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/yadda ${PREFIX}/sbin

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

.include <bsd.port.post.mk>
