# New ports collection makefile for:	Ruby/Pcap
# Date created:		20 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.6
CATEGORIES=	net ruby
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-pcap-dir=/usr
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/pcap
	${CP} -R ${WRKSRC}/examples/ ${RUBY_EXAMPLESDIR}/pcap/
	${MKDIR} ${RUBY_DOCDIR}/pcap/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/doc/* \
		${RUBY_DOCDIR}/pcap/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/doc-ja/* \
		${RUBY_DOCDIR}/pcap/ja/
.endif

.include <bsd.port.mk>
