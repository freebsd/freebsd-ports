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

LICENSE=	APACHE20

USE_APACHE=	22+
USES=		gmake
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf libtool
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} --with-expat=${LOCALBASE}

MAKE_ENV+=     MAKE=${GMAKE} ## MakeMaker blows it without this

SHLIB_MAJOR=	11
PLIST_SUB=	SHLIB_MAJOR="${SHLIB_MAJOR}"

# www/p5-libapreq2
.if defined (WITH_MODPERL2)
PLIST_SUB+=	WITH_MODPERL2=""
PKGNAMEPREFIX=	p5-
USES+=		perl5

P5_APREQ_DEPENDS+=	${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-ExtUtils-XSBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

BUILD_DEPENDS+=	${P5_APREQ_DEPENDS}
RUN_DEPENDS+=	${P5_APREQ_DEPENDS}

CONFIGURE_ARGS+=	--enable-perl-glue --with-perl=${PERL5}

post-patch:
	@${REINPLACE_CMD} -i '' -e "s!%%APACHEINCLUDEDIR%%!${APACHEINCLUDEDIR}!" \
		${WRKSRC}/glue/perl/Makefile.PL
.else
PLIST_SUB+=	WITH_MODPERL2="@comment "
.endif

.include <bsd.port.mk>
