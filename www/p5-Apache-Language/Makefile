# New ports collection makefile for:	Apache-Language
# Date created:				Mon Jan  1 05:22:52 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-Language
PORTVERSION=	0.14
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Apache/src.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/I18N/LangTags.pm:${PORTSDIR}/misc/p5-I18N-LangTags

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::Language.3 Apache::Language::Constants.3 \
		Apache::Language::DBI.3 Apache::Language::PlainFile.3

.include <bsd.port.mk>
