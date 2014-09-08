# Created by: stas
# $FreeBSD$

PORTNAME=	philesight
PORTVERSION=	20090105
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	http://zevv.nl/play/code/philesight/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows a graphics representation of the filesystem usage

RUN_DEPENDS=	rubygem-cairo>=0:${PORTSDIR}/graphics/rubygem-cairo \
		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_SITELIBDIR}/locale.rb:${PORTSDIR}/devel/ruby-locale2

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv
NO_BUILD=	yes
RUBY_SHEBANG_FILES=	${PORTNAME} ${PORTNAME}.rb ${PORTNAME}.cgi

PLIST_FILES=	bin/${PORTNAME} ${RUBY_SITELIBDIR:C,^${PREFIX}/?,,}/${PORTNAME}.rb
PORTEXAMPLES=	${PORTNAME}.cgi

OPTIONS_DEFINE=	EXAMPLES

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ruby19

DEPRECATED=	Depends on deprecated devel/ruby-locale2
EXPIRATION_DATE=	2014-09-20

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.rb ${STAGEDIR}${RUBY_SITELIBDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
