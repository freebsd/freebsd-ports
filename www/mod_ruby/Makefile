# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	0.8.0
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
LIB_DEPENDS=	eruby.1:${PORTSDIR}/textproc/eruby
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

USE_RUBY=	yes

APXS=		${LOCALBASE}/sbin/apxs

CONFIGURE_ARGS=	--apxs="${APXS}" \
		--enable-eruby=yes \
		--eruby-includes="${LOCALBASE}/include" \
		--eruby-libraries="${LOCALBASE}/lib"

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja
EXAMPLES_EN=	ruby/*

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} ${RUBY_FLAGS} Makefile.RB ${CONFIGURE_ARGS}

do-install:
	${APXS} -i -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME} ${PREFIX}/etc/apache/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
.for f in ${EXAMPLES_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/${PORTNAME}/
.endfor
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
