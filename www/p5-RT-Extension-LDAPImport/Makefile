# New ports collection Makefile for: RT-Extension-LDAPImport
# Date created:	        24 August 2008
# Whom:                 Matthew Seaman <m.seaman@infracaninophile.co.uk>
#
# $FreeBSD$
#

PORTNAME=	RT-Extension-LDAPImport
PORTVERSION=	0.04
CATEGORIES=	www net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	m.seaman@infracaninophile.co.uk
COMMENT=	RT extension to import users from an LDAP store

BUILD_DEPENDS=	${LOCALBASE}/${RTHOME}/bin/rt:${PORTSDIR}/www/rt36 \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

RTHOME?=	rt3
PLIST_SUB+=	RTHOME=${RTHOME}

PERL_CONFIGURE=	yes
CONFIGURE_ENV+=	RTHOME=${PREFIX}/${RTHOME}

MAN3=		RT::Extension::LDAPImport.3

# Don't use normal CONFIGURE_ARGS
do-configure:
	@cd ${CONFIGURE_WRKSRC} && \
	    ${SETENV} ${CONFIGURE_ENV} ${PERL5} ./${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
