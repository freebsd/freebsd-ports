# Created by: Autrijus Tang <autrijus@autrijus.org>
# $FreeBSD$

PORTNAME=	libapreq2
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	www devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq

MAINTAINER=	apache@FreeBSD.org
COMMENT=	Generic Apache2 Request Library

USE_APACHE=	22+
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf libtool
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}

MAKE_ENV+=     MAKE=${GMAKE} ## MakeMaker blows it without this

SHLIB_MAJOR=	11
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

.if defined (WITH_MODPERL2)
PKGNAMEPREFIX+=	p5-

P5_APREQ_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-ExtUtils-XSBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent
BUILD_DEPENDS+=	${P5_APREQ_DEPENDS}
RUN_DEPENDS+=	${P5_APREQ_DEPENDS}

USES+=		perl5
CONFIGURE_ARGS+=	--enable-perl-glue --with-perl=${PERL5}

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}
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
	@${REINPLACE_CMD} -i '' -e "s!%%APACHEINCLUDEDIR%%!${APACHEINCLUDEDIR}!" \
		${WRKSRC}/glue/perl/Makefile.PL
.else
PLIST_SUB+=	WITH_MODPERL2="@comment "
.endif

.include <bsd.port.mk>
