# Created by: Stephen J. Roznowski <sjr@home.net>
# $FreeBSD$

PORTNAME=	SNMP_Session
PORTVERSION=	1.13
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PROJECTHOST=	snmp-session
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl5 module providing rudimentary access to SNMPv1 and v2 agents

USES=		perl5
USE_PERL5=	configure

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.options.mk>

post-patch:
	${RM} ${WRKSRC}/lib/SNMP_Session.pm.orig

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README README.SNMP_util index.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor


.include <bsd.port.mk>
