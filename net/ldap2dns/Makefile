# New ports collection makefile for:	ldap2dns
# Date created:				29 September 2003
# Whom:					Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldap2dns
PORTVERSION=	0.3.6
CATEGORIES=	net
MASTER_SITES=	http://projects.alkaloid.net/dist/ldap2dns/

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Maintain DNS zones using an LDAP directory

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap

USE_GMAKE=	yes
USE_OPENLDAP=	yes
USE_PERL5=	yes

MAKE_ENV=	PREFIX=${PREFIX} INC=-I${PREFIX}/include LIB=-L${PREFIX}/lib

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/ldap2dns.c
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX}," ${WRKSRC}/ldap2tinydns-conf

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2dns ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2dnsd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/ldap2dns.schema ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/example.ldif ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/doc/README.html ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldap2tinydns-conf ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/axfr2ldap.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/data2ldap.pl ${DATADIR}

.include <bsd.port.mk>
