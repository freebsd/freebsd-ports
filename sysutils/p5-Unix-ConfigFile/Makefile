# New ports collection makefile for:	Unix-ConfigFile
# Date created:				Wed Jan  3 09:43:27 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Unix-ConfigFile
PORTVERSION=	0.06
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Unix
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Perl modules that provides a simple interface to reading /etc files

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Unix::GroupFile.3 Unix::AliasFile.3 \
		Unix::PasswdFile.3 Unix::AutomountFile.3

.include <bsd.port.mk>
