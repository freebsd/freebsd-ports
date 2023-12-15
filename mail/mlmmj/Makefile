PORTNAME=	mlmmj
PORTVERSION=	1.4.1
CATEGORIES=	mail
MASTER_SITES=	https://codeberg.org/mlmmj/mlmmj/releases/download/RELEASE_${PORTVERSION:S/./_/g}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Simple and slim mailing list manager
WWW=		http://mlmmj.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake iconv shebangfix tar:xz pkgconfig
SHEBANG_FILES=	contrib/web/perl-user/mlmmj.cgi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-receive-strip

CPPFLAGS+=	-I${ICONV_INCLUDE_PATH}
LDFLAGS+=	${ICONV_LIB_PATH}

OPTIONS_DEFINE=		DOCS PERL PHP
OPTIONS_SUB=		yes

PERL_RUN_DEPENDS=	p5-URI>0:net/p5-URI \
			p5-CGI-FastTemplate>0:www/p5-CGI-FastTemplate \
			p5-HTML-Parser>0:www/p5-HTML-Parser
PHP_USES=		php:web

BUILD_DEPENDS=		kyua:devel/kyua \
			atf-sh:devel/atf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} \
		ChangeLog FAQ README* TODO TUNABLES UPGRADE \
		${STAGEDIR}${DOCSDIR})

post-install-PERL-on:
	@(cd ${WRKSRC}/contrib/web && ${COPYTREE_SHARE} "perl-*" \
		${STAGEDIR}${WWWDIR})
	@${CHMOD} ${BINMODE} ${STAGEDIR}${WWWDIR}/perl-user/mlmmj.cgi

post-install-PHP-on:
	@(cd ${WRKSRC}/contrib/web && ${COPYTREE_SHARE} "php-*" \
		${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
