# New ports collection makefile for:    shelldap
# Date created:         2006-07-07
# Whom:                 Mahlon E. Smith <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	shelldap
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.martini.nu/misc/

MAINTAINER=	mahlon@martini.nu
COMMENT=	A shell-like environment for LDAP

RUN_DEPENDS=	${SITE_PERL}/Algorithm/Diff.pm:${PORTSDIR}/devel/p5-Algorithm-Diff \
		${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap \
		${SITE_PERL}/Term/Shell.pm:${PORTSDIR}/devel/p5-Term-Shell \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadKey.pm:${PORTSDIR}/devel/p5-Term-ReadKey \
		${SITE_PERL}/${PERL_ARCH}/Term/ReadLine/Gnu.pm:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		${SITE_PERL}/${PERL_ARCH}/YAML/Syck.pm:${PORTSDIR}/textproc/p5-YAML-Syck

USE_PERL5=	yes

MAN1=		shelldap.1

PLIST_FILES=	bin/shelldap

NO_BUILD=	yes

post-extract:
	${MKDIR} ${WRKSRC}/man/man1
	${LOCALBASE}/bin/pod2man < ${WRKSRC}/shelldap > ${WRKSRC}/man/man1/shelldap.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/man/man1/shelldap.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/shelldap ${PREFIX}/bin

.include <bsd.port.mk>
