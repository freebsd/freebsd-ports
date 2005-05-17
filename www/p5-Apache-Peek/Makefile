# New ports collection makefile for:	p5-Apache-Peek
# Date created:		24-Jul-2000
# Whom:			Leo Kim <leo@florida.sarang.net>
#
# $FreeBSD$
#

PORTNAME=	Apache-Peek
PORTVERSION=	1.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/S/ST/STAS
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	A data debugging tool for the XS programmer (under mod_perl)

.if defined(WITH_MODPERL2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/mod_perl.pm:${PORTSDIR}/www/mod_perl2
MOD_PERL=	2
.else
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
MOD_PERL=	1
.endif

PERL_CONFIGURE=	YES

CONFIGURE_ARGS=	-httpd ${LOCALBASE}/sbin/httpd

MAN3=		Apache::Peek.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Devel/Peek.pm:${PORTSDIR}/devel/p5-Devel-Peek
.endif

RUN_DEPENDS=	${BUILD_DEPENDS}

post-patch:
	@${PERL} -pi -e '$$_="" if /^test_configure\(/;' ${WRKSRC}/Makefile.PL

.include <bsd.port.post.mk>
