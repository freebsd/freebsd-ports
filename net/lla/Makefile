# New ports collection makefile for:	LDAP logfile Analyzer
# Date created:				2 May 2001
# Whom:					Sunagawa Koji <koj@ofug.net>
#
# $FreeBSD$
#

PORTNAME=	lla
PORTVERSION=	0.98p14
CATEGORIES=	net perl5
MASTER_SITES=	http://www.umldap.com/lla/
DISTNAME=	lla.pl
EXTRACT_SUFX=

MAINTAINER=	koj@ofug.net

RUN_DEPENDS=	${SITE_ARCH_PERL}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Time/ParseDate.pm:${PORTSDIR}/devel/p5-Time

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	.

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
SITE_ARCH_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}

do-install:
	${CP} ${WRKDIR}/${DISTNAME} ${PREFIX}/bin
	${CHMOD} 755 ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>
