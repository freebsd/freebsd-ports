# Created by: stas
# $FreeBSD$

PORTNAME=	philesight
PORTVERSION=	20090105
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://zevv.nl/play/code/philesight/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Shows a graphics representation of the filesystem usage

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/cairo.so:${PORTSDIR}/graphics/ruby-cairo \
		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb \
		${RUBY_SITELIBDIR}/locale.rb:${PORTSDIR}/devel/ruby-locale2 \
		${RUBY_ARCHLIBDIR}/iconv.so:${PORTSDIR}/converters/ruby-iconv

USE_RUBY=	yes
NO_BUILD=	yes
RUBY_SHEBANG_FILES=	${PORTNAME} ${PORTNAME}.rb ${PORTNAME}.cgi

PLIST_FILES=	bin/${PORTNAME} ${RUBY_SITELIBDIR:C,^${PREFIX}/?,,}/${PORTNAME}.rb

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	${PORTNAME}.cgi
.endif

NO_STAGE=	yes
.include <bsd.port.pre.mk>

EXTRA_PATCHES=	${FILESDIR}/extra-patch-ruby19

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.rb ${RUBY_SITELIBDIR}/

.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
. for FILE in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${EXAMPLESDIR}/
. endfor
.endif

.include <bsd.port.post.mk>
