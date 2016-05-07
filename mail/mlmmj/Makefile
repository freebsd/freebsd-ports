# Created by: Christian Laursen <xi@borderworlds.dk>
# $FreeBSD$

PORTNAME=	mlmmj
PORTVERSION=	1.2.19.0
CATEGORIES=	mail
MASTER_SITES=	http://mlmmj.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple and slim mailing list manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cpe gmake iconv shebangfix tar:bzip2
SHEBANG_FILES=	contrib/web/perl-user/mlmmj.cgi
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${ICONV_INCLUDE_PATH}
LDFLAGS+=	${ICONV_LIB_PATH}

OPTIONS_DEFINE=		DOCS PERL PHP
OPTIONS_SUB=		yes

PERL_RUN_DEPENDS=	p5-URI>0:net/p5-URI \
			p5-CGI-FastTemplate>0:www/p5-CGI-FastTemplate \
			p5-HTML-Parser>0:www/p5-HTML-Parser
PHP_USE=		php=yes
PHP_VERS=		WANT_PHP_WEB=yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^AM_CFLAGS/s|-g ||' ${WRKSRC}/src/Makefile.in

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
