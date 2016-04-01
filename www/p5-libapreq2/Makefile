# $FreeBSD$

PORTNAME=	libapreq2
PORTVERSION=	2.13
PORTREVISION=	6
CATEGORIES=	www perl5 devel
MASTER_SITES=	APACHE_HTTPD/libapreq
DISTFILE=	libapreq2-${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl binding for the Generic Apache2 Request Library

LICENSE=	APACHE20

USES=		gmake libtool perl5
USE_APACHE=	22+
USE_PERL5=	run
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	autoconf
CONFIGURE_ARGS+=	--with-apache2-apxs=${APXS} \
			--with-expat=${LOCALBASE} \
			--enable-perl-glue --with-perl=${PERL}

MAKE_ENV+=     MAKE=${GMAKE} ## MakeMaker blows it without this

BUILD_DEPENDS=	libapreq2>0:www/libapreq2 \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2 \
		p5-ExtUtils-XSBuilder>=0:devel/p5-ExtUtils-XSBuilder \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

RUN_DEPENDS=	libapreq2>0:www/libapreq2 \
		${APACHE_PKGNAMEPREFIX}mod_perl2>=0:www/mod_perl2 \
		p5-Parse-RecDescent>=0:devel/p5-Parse-RecDescent

post-patch:
	@${REINPLACE_CMD} -i '' -e "s!%%APACHEINCLUDEDIR%%!${APACHEINCLUDEDIR}!" \
		${WRKSRC}/glue/perl/Makefile.PL
post-stage:
	# remove all the non-perl stuff
	${RM} ${STAGEDIR}${PREFIX}/bin/apreq2-config
	${RM} -rf ${STAGEDIR}${PREFIX}/include/apreq2
	${RM} ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}/apreq2/apreq_module_apache2.h
	${RM} ${STAGEDIR}${PREFIX}/lib/libapreq2*
	${RM} ${STAGEDIR}${PREFIX}/${APACHEMODDIR}/mod_apreq2*
	${RMDIR} -p ${STAGEDIR}${PREFIX}/${APACHEINCLUDEDIR}/apreq2 \
		${STAGEDIR}${PREFIX}/${APACHEMODDIR} 2>/dev/null || :
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/APR/Request/Request.so
.for i in Apache2 CGI Cookie Error Hook Param Parser
	${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/APR/Request/${i}/${i}.so
.endfor

.include <bsd.port.mk>
