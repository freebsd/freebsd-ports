# New ports collection makefile for:	ldapsh
# Date created:				Jul 28 2004
# Whom:					Florent Thoumie <flz@xbsd.org>
#
# $FreeBSD$
#

PORTNAME=	ldapsh
PORTVERSION=	2.0.b1
CATEGORIES=	net
MASTER_SITES=	http://madstop.com/ldapsh/
DISTNAME=	ldapsh-2.0b1
EXTRACT_SUFX=	.tgz

MAINTAINER=	flz@xbsd.org
COMMENT=	Interactive shell used to administer ldap directories

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/Parse/RecDescent.pm:${PORTSDIR}/devel/p5-Parse-RecDescent
RUN_DEPENDS=	${BUILD_DEPENDS}

PKGMESSAGE=	${WRKDIR}/pkg-message

SED_SCRIPT=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DOCSDIR%%,${DOCSDIR},g' \
		-e 's,%%EXAMPLESDIR%%,${EXAMPLESDIR},g'

USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/ldapsh

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e "s,/usr/local/bin/perl,${PERL}," ${WRKSRC}/ldapsh

pre-install:
	${SED} ${SED_SCRIPT} ${PKGDIR}/pkg-message > ${WRKDIR}/pkg-message

do-install:
	${MKDIR} ${DOCSDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/COMMANDS ${DOCSDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/ldapsh ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/examples/LdapConfig.pl ${EXAMPLESDIR}/LdapConfig.pl
	${CP} -r ${WRKSRC}/lib/Net ${SITE_PERL}

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
