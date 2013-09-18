# Created by: Mahlon E. Smith <mahlon@martini.nu>
# $FreeBSD$

PORTNAME=	shelldap
PORTVERSION=	1.0.0
CATEGORIES=	net perl5
MASTER_SITES=	http://dl.dropbox.com/u/7234177/Releases/ \
		http://www.martini.nu/misc/

MAINTAINER=	mahlon@martini.nu
COMMENT=	Shell-like environment for LDAP

RUN_DEPENDS=	p5-Algorithm-Diff>=0:${PORTSDIR}/devel/p5-Algorithm-Diff \
		p5-perl-ldap>=0:${PORTSDIR}/net/p5-perl-ldap \
		p5-Term-Shell>=0:${PORTSDIR}/devel/p5-Term-Shell \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-ReadLine-Gnu>=0:${PORTSDIR}/devel/p5-ReadLine-Gnu \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck

USES=		perl5
USE_PERL5=	extract build run
MAN1=		shelldap.1

PLIST_FILES=	bin/shelldap

NO_BUILD=	yes

post-extract:
	${LOCALBASE}/bin/pod2man < ${WRKSRC}/shelldap > ${WRKSRC}/shelldap.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/shelldap.1 ${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/shelldap ${PREFIX}/bin

.include <bsd.port.mk>
