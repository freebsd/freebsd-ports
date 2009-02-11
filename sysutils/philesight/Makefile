# New ports collection makefile for:	philesight
# Date created:		2009-02-11
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	philesight
PORTVERSION=	20090105
CATEGORIES=	sysutils
MASTER_SITES=	http://zevv.nl/play/code/philesight/
EXTRACT_SUFX=	.tgz

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Shows a graphics representation of the filesystem usage

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/cairo.so:${PORTSDIR}/graphics/ruby-cairo \
		${RUBY_SITEARCHLIBDIR}/bdb.so:${PORTSDIR}/databases/ruby-bdb

USE_RUBY=	yes
NO_BUILD=	yes
RUBY_SHEBANG_FILES=	${PORTNAME} ${PORTNAME}.rb ${PORTNAME}.cgi

PORTEXAMPLES=	${PORTNAME}.cgi
PLIST_FILES=	bin/${PORTNAME} ${RUBY_SITELIBDIR:C,^${PREFIX}/?,,}/${PORTNAME}.rb

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ruby19
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.rb ${RUBY_SITELIBDIR}/

.if !defined(WITHOUT_EXAMPLES)
	${MKDIR} ${EXAMPLESDIR}/
. for FILE in ${PORTEXAMPLES}
	${INSTALL_SCRIPT} ${WRKSRC}/${FILE} ${EXAMPLESDIR}/
. endfor
.endif

.include <bsd.port.post.mk>
