# New ports collection makefile for:	p5-Apache-ASP
# Date created:				31 December 1999
# Whom:					Igor Vinokurov <igor@zynaps.ru>
#
# $FreeBSD$
#

PORTNAME=	Apache-ASP
PORTVERSION=	2.49
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@lansing.dk

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/Filter.pm:${PORTSDIR}/www/p5-Apache-Filter \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/SSI.pm:${PORTSDIR}/www/p5-Apache-SSI \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MLDBM/Sync.pm:${PORTSDIR}/databases/p5-MLDBM-Sync \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Tie/Cache.pm:${PORTSDIR}/devel/p5-Tie-Cache \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/XML/XSLT.pm:${PORTSDIR}/textproc/p5-XML-XSLT \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/XML/Sablotron.pm:${PORTSDIR}/textproc/p5-XML-Sablotron
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		asp-perl.1
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::ASP.3 \
		Apache::ASP::CGI::Table.3 \
		Bundle::Apache::ASP.3 \
		Bundle::Apache::ASP::Extra.3

.include <bsd.port.mk>
