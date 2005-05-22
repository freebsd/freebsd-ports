# New ports collection makefile for:	p5-libapreq2
# Date created:				June 5, 2004
# Whom:	      				Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	libapreq2
PORTVERSION=	2.05
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION}-dev

MAINTAINER=	autrijus@autrijus.org
COMMENT=	Generic Apache2 Request Library

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl2.pm:${PORTSDIR}/www/mod_perl2 \
		${SITE_PERL}/ExtUtils/XSBuilder:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder
RUN_DEPENDS=	${BUILD_DEPENDS}

WITH_APACHE2=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-perl-glue --with-apache2-apxs=${APXS}
USE_PERL5=	yes
USE_APACHE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/_[0-9]+//}

post-configure:
	cd ${CONFIGURE_WRKSRC}/glue/perl && \
		${PERL5} Makefile.PL -apxs ${APXS} && \
		${PERL5} -pi -e 's/ doc_(perl|site|\$$\(INSTALLDIRS\))_install$$//' Makefile

.include <bsd.port.mk>
