# New ports collection makefile for:    p5-I18N-Charset
# Date created:			26 December 1999
# Whom:	      			Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	I18N-Charset
PORTVERSION=	1.23
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	I18N
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IO/String.pm:${PORTSDIR}/devel/p5-IO-String \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Test/Simple.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/File/Which.pm:${PORTSDIR}/sysutils/p5-File-Which

PERL_CONFIGURE=	YES

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		I18N::Charset.3

.include <bsd.port.mk>
