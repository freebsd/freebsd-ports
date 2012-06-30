# New ports collection makefile for:    shelldap
# Date created:         2006-07-07
# Whom:                 Mahlon E. Smith <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	shelldap
PORTVERSION=	0.5
CATEGORIES=	net perl5
MASTER_SITES=	http://www.martini.nu/misc/

MAINTAINER=	mahlon@martini.nu
COMMENT=	A shell-like environment for LDAP

RUN_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Term-Shell>=0:${PORTSDIR}/devel/p5-Term-Shell \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck

USE_PERL5=	yes

MAN1=		shelldap.1

PLIST_FILES=	bin/shelldap

NO_BUILD=	yes

post-extract:
	${LOCALBASE}/bin/pod2man < ${WRKSRC}/shelldap > ${WRKSRC}/shelldap.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/shelldap.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/shelldap ${PREFIX}/bin

.include <bsd.port.mk>
