# New ports collection makefile for:	p5-Apache-Session-SQLite3
# Date created:				March 17, 2005
# Whom:					clsung
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-SQLite3
PORTVERSION=	0.03
CATEGORIES=	www databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Use DBD::SQLite 1.x for Apache::Session storage

BUILD_DEPENDS=	${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/${PERL_ARCH}/DBD/SQLite.pm:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Session::SQLite3.3

.include <bsd.port.mk>
