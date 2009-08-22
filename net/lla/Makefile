# New ports collection makefile for:	LDAP logfile Analyzer
# Date created:				2 May 2001
# Whom:					Sunagawa Koji <koj@ofug.net>
#
# $FreeBSD$
#

PORTNAME=	lla
PORTVERSION=	0.99.1
CATEGORIES=	net perl5
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.pl

MAINTAINER=	koj@ofug.net
COMMENT=	Perl-based LDAP log statistics generator

RUN_DEPENDS=	${SITE_ARCH_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time-modules

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PERL5=	yes
PLIST_FILES=	bin/lla

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	
EXTRACT_AFTER_ARGS=	./${PORTNAME}

SITE_ARCH_PERL=	${SITE_PERL}/${PERL_ARCH}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
