# New ports collection makefile for:	mod_ruby
# Date created:			12 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mod_ruby
PORTVERSION=	${VERSION}
PORTREVISION=	1
CATEGORIES=	www ruby
MASTER_SITES=	http://www.modruby.net/archive/
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13
LIB_DEPENDS=	eruby.1:${PORTSDIR}/textproc/eruby
RUN_DEPENDS=	${APXS}:${PORTSDIR}/www/apache13

USE_RUBY=	yes
RUBY_REQUIRE=	160 <= Ruby

.include <bsd.port.pre.mk>

.if defined(RUBY_PROVIDED)
VERSION=	0.2.2
.else
VERSION=	0.2.0
.endif

APXS=		${LOCALBASE}/sbin/apxs

CONFIGURE_ARGS=	--apxs="${APXS}" \
		--enable-eruby=yes \
		--eruby-includes="${LOCALBASE}/include" \
		--eruby-libraries="${LOCALBASE}/lib"

DOCS_EN=	ChangeLog README.en
DOCS_JA=	README.ja

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${RUBY} Makefile.RB ${CONFIGURE_ARGS}

do-install:
	${APXS} -i -n ruby ${WRKSRC}/mod_ruby.so
	${INSTALL_DATA} ${FILESDIR}/httpd.conf.${PORTNAME} ${PREFIX}/etc/apache/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
