# New ports collection makefile for:	p5-Unix-Syslog
# Date created:				November 19th 2000
# Whom:					Blaz Zupan <blaz@amis.net>
#
# $FreeBSD$
#

PORTNAME=	Unix-Syslog
PORTVERSION= 	0.94
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unix
PKGNAMEPREFIX=	p5-
DISTNAME=	Syslog-${PORTVERSION}

MAINTAINER=	blaz@amis.net

USE_PERL5=	yes

MAN3=		Unix::Syslog.3

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
	@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL \
		CC="${CC}" CCFLAGS="${CFLAGS}"

.include <bsd.port.mk>
