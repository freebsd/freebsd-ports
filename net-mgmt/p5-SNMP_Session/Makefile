# New ports collection makefile for:	p5-SNMP_Session
# Date created:				13 June 1999
# Whom:					Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	SNMP_Session
PORTVERSION=	0.83
CATEGORIES=	net perl5
MASTER_SITES=	ftp://ftp.switch.ch/software/sources/network/snmp/perl/
PKGNAMEPREFIX=	p5-

MAINTAINER=	petef@databits.net

PERL_CONFIGURE=	yes

post-configure:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/Makefile;

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/p5-SNMP_Session
	${INSTALL_DATA} ${WRKSRC}/README.SNMP_util \
		${PREFIX}/share/doc/p5-SNMP_Session
.endif

.include <bsd.port.mk>
