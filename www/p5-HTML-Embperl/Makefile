# New ports collection makefile for:	p5-HTML-Embperl
# Date created:				March 13, 2000
# Whom:	      				Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	HTML-Embperl
PORTVERSION=	1.3.3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	kapr@crosswinds.net

.if !defined(WITHOUT_APACHE)
BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
.endif

PERL_CONFIGURE=	yes
.if !defined(WITHOUT_APACHE)
CONFIGURE_ARGS=	DEFINE=-DAPACHE INC=-I${LOCALBASE}/include/apache
.endif

INSTALL_TARGET=	pure_install

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::Embperl.3 HTML::EmbperlD.3 HTML::EmbperlObject.3
MAN1=		embpexec.pl.1

pre-configure:
	${CP} -f ${FILESDIR}/Makefile.PL ${WRKSRC}

.include <bsd.port.mk>
