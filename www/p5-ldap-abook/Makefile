# New ports collection makefile for:	p5-abook
# Date created:				November 22, 2004
# Whom:	      				Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldap-abook
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl5 CGI script providing an LDAP addressbook web interface

RUN_DEPENDS=	${SITE_PERL}/AddressBook.pm:${PORTSDIR}/net/p5-AddressBook \
		${SITE_PERL}/CGI.pm:${PORTSDIR}/www/p5-CGI.pm

ABOOK=		${PREFIX}/www/ldap-abook
CONFIG=		${PREFIX}/etc/AddressBook.conf
USE_PERL5=	yes
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e 's|(/etc/AddressBook.conf)|${PREFIX}$$1|g' \
	   ${WRKSRC}/cgi-bin/abook.cgi

do-install:
	@ ${MKDIR} ${PREFIX}/www/ldap-abook
	${TAR} -C ${WRKSRC} --exclude '*.orig' -cf - . | \
	    ${TAR} -C ${PREFIX}/www/ldap-abook -xf -
	${INSTALL_DATA} ${FILESDIR}/abook.ldif ${ABOOK}/examples/default
	${INSTALL_DATA} ${ABOOK}/examples/default/AddressBook.conf \
	    ${CONFIG}-dist
	[ -f ${CONFIG} ] || \
	    install  -o root -g www -m 640 ${CONFIG}-dist ${CONFIG}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
