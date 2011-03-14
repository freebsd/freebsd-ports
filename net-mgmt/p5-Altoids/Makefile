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
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SNMP get/walk functionality with built-in name to OID translation

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	${SITE_PERL}/SNMP_Session.pm:${PORTSDIR}/net-mgmt/p5-SNMP_Session
RUN_DEPENDS=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USE_PERL5=	yes

CONFIGURE_ARGS+=	--with-perllib=${SITE_PERL} \
			--with-oids=${LOCALBASE}/share/${PORTNAME:L}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
