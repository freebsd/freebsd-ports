# New ports collection makefile for:	Ruby/Pcap
# Date created:		20 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	pcap
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	http://www.goto.info.waseda.ac.jp/~fukusima/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to LBL Packet Capture library (libpcap)

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-pcap-dir=/usr
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${WRKSRC}/README ${WRKSRC}/doc/* \
		${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.ja ${WRKSRC}/doc-ja/* \
		${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
