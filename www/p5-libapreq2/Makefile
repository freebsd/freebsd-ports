# $FreeBSD$

PORTNAME=	libapreq2
PORTVERSION=	2.13
PORTREVISION=	4
CATEGORIES=	www perl5 devel
MASTER_SITES=	${MASTER_SITE_APACHE_HTTPD}
MASTER_SITE_SUBDIR=libapreq
DISTFILE=	libapreq2-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl binding for the Generic Apache2 Request Library

LICENSE=	APACHE20

USES=		gmake libtool perl5
USE_APACHE=	22+
USE_PERL5=	fixpacklist run
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} \
			--with-expat=${LOCALBASE} \
			--enable-perl-glue --with-perl=${PERL5}

MAKE_ENV+=     MAKE=${GMAKE} ## MakeMaker blows it without this

BUILD_DEPENDS=	libapreq2>0:${PORTSDIR}/www/libapreq2 \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-ExtUtils-XSBuilder>=0:${PORTSDIR}/devel/p5-ExtUtils-XSBuilder \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

RUN_DEPENDS=	libapreq2>0:${PORTSDIR}/www/libapreq2 \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:${PORTSDIR}/www/mod_perl2 \
		p5-Parse-RecDescent>=0:${PORTSDIR}/devel/p5-Parse-RecDescent

post-patch:
	@${REINPLACE_CMD} -i '' -e "s!%%APACHEINCLUDEDIR%%!${APACHEINCLUDEDIR}!" \
		${WRKSRC}/glue/perl/Makefile.PL
post-stage:
	# remove all the non-perl stuff
	${RM} ${STAGEDIR}${PREFIX}/bin/apreq2-config
	${RM} -rf ${STAGEDIR}${PREFIX}/include/apreq2
	${RM} ${STAGEDIR}${PREFIX}/include/apache22/apreq2/apreq_module_apache2.h
	${RM} ${STAGEDIR}${PREFIX}/lib/libapreq2*
	${RM} ${STAGEDIR}${PREFIX}/libexec/apache22/mod_apreq2*
	${FIND} ${STAGEDIR} -name '*.bs' -type f -size 0c -exec ${RM} {} \;
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/APR/Request/Request.so
.for i in Apache2 CGI Cookie Error Hook Param Parser
	${STRIP_CMD} \
		${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/APR/Request/${i}/${i}.so
.endfor

.include <bsd.port.mk>
