# New ports collection makefile for:	Ruby-SNMP
# Date created:		1 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	snmp
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	net-mgmt ruby
MASTER_SITES=	http://w3cic.riken.go.jp/~tsuruoka/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	seanc@FreeBSD.org
COMMENT=	Ruby interface to UCD-SNMP library

IGNORE=		is unusable, cf. ports/47957

LIB_DEPENDS=	snmp.4:${PORTSDIR}/net-mgmt/net-snmp4

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

WRKSRC=		${WRKDIR}/SNMP
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-snmp-dir="${LOCALBASE}"

DOCS_EN=	mib_view.html \
		rubysnmp.html \
		sampleout.html \
		snmp_module.html \
		snmp_session.html \
		snmp_var.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
