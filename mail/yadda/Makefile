# New ports collection makefile for:	yadda
# Date created:		2004-01-01
# Whom:			Jesper Noehr <jesper@noehr.org>
#
# $FreeBSD$
#

PORTNAME=	yadda
PORTVERSION=	1.0
CATEGORIES=	mail
MASTER_SITES=	http://code.printf.dk/~decius/yadda/ \
		http://users.cybercity.dk/~dsl22381/

MAINTAINER=	jesper@noehr.org
COMMENT=	Yet Another Damn Delivery Agent

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI \
		${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit

USE_PERL5_RUN=	yes

do-build:
	${SED} -e '1s,/usr/bin/perl,${PERL},' ${WRKSRC}/yadda \
		> ${WRKDIR}/yadda

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/yadda ${PREFIX}/sbin

.include <bsd.port.mk>
