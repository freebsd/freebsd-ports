# New ports collection makefile for:	ldapsh
# Date created:				Jul 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ldapsh
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://madstop.com/ldapsh/
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@xbsd.org
COMMENT=	Interactive shell used to administer ldap directories

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/ldapsh

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
.endif

do-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COMMANDS ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldapsh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/LdapConfig.pl ${PREFIX}/etc/LdapConfig.pl.sample
	${CP} -r ${WRKSRC}/lib/Net ${SITE_PERL}

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local/bin/perl,${PERL}," ${WRKSRC}/ldapsh

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
