# New ports collection makefile for:	p5-Altoids
# Date created:				13 June 1999
# Whom:					Bill Fumerola <billf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Altoids
PORTVERSION=	1.017
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://dave.plonka.us/Altoids/%SUBDIR%/
MASTER_SITE_SUBDIR=	. old
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	billf@FreeBSD.org
COMMENT=	SNMP get/walk functionality with built-in name to OID translation

BUILD_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--with-perllib=${SITE_PERL} \
			--with-oids=${LOCALBASE}/share/${PORTNAME:L}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
