# New ports collection makefile for:	p5-Apache-ASP
# Date created:				31 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-ASP
PORTVERSION=	2.57
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Active Server Pages for Apache with mod_perl

BUILD_DEPENDS=	${SITE_PERL}/Apache/Filter.pm:${PORTSDIR}/www/p5-Apache-Filter \
		${SITE_PERL}/Apache/SSI.pm:${PORTSDIR}/www/p5-Apache-SSI \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${SITE_PERL}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/MLDBM/Sync.pm:${PORTSDIR}/databases/p5-MLDBM-Sync \
		${SITE_PERL}/Tie/Cache.pm:${PORTSDIR}/devel/p5-Tie-Cache \
		${SITE_PERL}/XML/XSLT.pm:${PORTSDIR}/textproc/p5-XML-XSLT \
		${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		asp-perl.1
MAN3=		Apache::ASP.3 \
		Apache::ASP::CGI::Table.3 \
		Bundle::Apache::ASP.3 \
		Bundle::Apache::ASP::Extra.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes
.endif

.include <bsd.port.post.mk>
