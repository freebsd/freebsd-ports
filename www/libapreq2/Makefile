# New ports collection makefile for:	p5-libapreq2
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	libapreq2
PORTVERSION=	2.07
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generic Apache2 Request Library

WITH_APACHE2=	yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS}
USE_APACHE=	yes

.if defined (WITH_MODPERL2)
PKGNAMEPREFIX+=	p5-

BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/ExtUtils/XSBuilder:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-perl-glue

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		APR::Request.3 \
		APR::Request::Apache2.3 \
		APR::Request::CGI.3 \
		APR::Request::Cookie.3 \
		APR::Request::Error.3 \
		APR::Request::Hook.3 \
		APR::Request::Param.3 \
		APR::Request::Parser.3 \
		Apache2::Cookie.3 \
		Apache2::Upload.3 \
		Apache2::Request.3

PLIST_SUB+=	WITH_MODPERL2=""

post-configure:
	cd ${WRKSRC}/glue/perl && \
		${PERL5} Makefile.PL -apxs ${APXS} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile
.else
PLIST_SUB+=	WITH_MODPERL2="@comment "
.endif

.include <bsd.port.mk>
