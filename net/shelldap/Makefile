# Created by: Mahlon E. Smith <mahlon@martini.nu>
# $FreeBSD$

PORTNAME=	shelldap
PORTVERSION=	1.5.1
DISTVERSIONPREFIX=	v
CATEGORIES=	net perl5

MAINTAINER=	mahlon@martini.nu
COMMENT=	Shell-like environment for LDAP

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	p5-Algorithm-Diff>=0:devel/p5-Algorithm-Diff \
		p5-perl-ldap>=0:net/p5-perl-ldap \
		p5-Term-Shell>=0:devel/p5-Term-Shell \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Term-ReadLine-Gnu>=0:devel/p5-Term-ReadLine-Gnu \
		p5-Tie-IxHash>=0:devel/p5-Tie-IxHash \
		p5-YAML-Syck>=0:textproc/p5-YAML-Syck

USES=		perl5
USE_PERL5=	extract build run

USE_GITHUB=	yes
GH_ACCOUNT=	mahlonsmith

PLIST_FILES=	bin/shelldap man/man1/shelldap.1.gz

NO_BUILD=	yes
NO_ARCH=	yes

post-extract:
	${LOCALBASE}/bin/pod2man ${WRKSRC}/shelldap ${WRKSRC}/shelldap.1

do-install:
	${INSTALL_MAN} ${WRKSRC}/shelldap.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/shelldap ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
