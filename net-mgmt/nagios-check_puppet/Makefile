PORTNAME=	check_puppet
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/
PKGNAMEPREFIX=	nagios-

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Nagios plugin for checking Puppet daemon availability
WWW=		http://renatasystems.org/freebsd/check_puppet.html

NO_BUILD=	yes

SUB_FILES=	pkg-message

PLIST_FILES=	bin/check_puppet share/man/man1/check_puppet.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/check_puppet ${STAGEDIR}${PREFIX}/bin/check_puppet
	${INSTALL_MAN} ${WRKSRC}/check_puppet.1 ${STAGEDIR}${PREFIX}/share/man/man1/check_puppet.1

.include <bsd.port.mk>
