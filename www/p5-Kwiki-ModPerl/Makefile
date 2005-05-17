# New ports collection makefile for:	p5-Kwiki-ModPerl
# Date created:		Wed Apr  6 16:30:34 CST 2005
# Whom:			clsung
#
# $FreeBSD$
#

PORTNAME=	Kwiki-ModPerl
PORTVERSION=	0.06
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Kwiki
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enable Kwiki to work under mod_perl

BUILD_DEPENDS=	${SITE_PERL}/Kwiki.pm:${PORTSDIR}/www/p5-Kwiki
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

.if defined(WITH_APACHE2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
pre-patch:
	@${REINPLACE_CMD} -e 's|mod_perl|Apache2::mod_perl|g' ${WRKSRC}/Makefile.PL
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif

MAN3=		Kwiki::ModPerl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=	This port requires perl 5.8.x or later. Install lang/perl5.8 then try again
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
