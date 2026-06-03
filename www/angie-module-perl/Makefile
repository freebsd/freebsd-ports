PORTNAME=	angie-module-perl

COMMENT=	Angie Perl dynamic module

LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5

CONFIGURE_ADD=	--with-http_perl_module=dynamic

CFLAGS+=	-Wno-compound-token-split-by-macro

MASTERDIR=	${.CURDIR}/../../www/angie

do-install:
	${MKDIR} ${STAGEDIR}${MODDIR} \
		 ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx

	${INSTALL_LIB} ${WRKSRC}/objs/ngx_http_perl_module.so \
	    ${STAGEDIR}${MODDIR}

	${INSTALL_LIB} ${WRKSRC}/objs/src/http/modules/perl/blib/arch/auto/nginx/nginx.so \
	    ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/nginx
	${INSTALL_DATA} ${WRKSRC}/objs/src/http/modules/perl/blib/lib/nginx.pm \
	    ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}

do-install-DEBUG-on:
	${INSTALL} ${COPY} -m ${_SHAREMODE} \
	    ${WRKSRC_DEBUG}/objs/ngx_http_perl_module.so \
	    ${STAGEDIR}${MODDIR}/ngx_http_perl_module-debug.so

.include "${MASTERDIR}/Makefile"
