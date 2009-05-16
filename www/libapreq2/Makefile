# New ports collection makefile for:	p5-libapreq2
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	libapreq2
PORTVERSION=	2.12
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Generic Apache2 Request Library

USE_APACHE=	2.0+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:15
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}

PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.if defined (WITH_MODPERL2)
PKGNAMEPREFIX+=	p5-

P5_APREQ_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/ExtUtils/XSBuilder:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS+=	${P5_APREQ_DEPENDS}
RUN_DEPENDS+=	${P5_APREQ_DEPENDS}

USE_PERL5=	yes
CONFIGURE_ARGS+=	--enable-perl-glue --with-perl=${PERL5}

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

post-patch:
	@${PERL5} -pi -e "s!%%APACHEINCLUDEDIR%%!${APACHEINCLUDEDIR}!" \
		${WRKSRC}/glue/perl/Makefile.PL
.else
PLIST_SUB+=	WITH_MODPERL2="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 20
SHLIB_MAJOR=	9
.else
SHLIB_MAJOR=	10
.endif

.include <bsd.port.post.mk>
