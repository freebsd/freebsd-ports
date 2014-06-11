# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_pGina
PORTVERSION=	1.1.3
CATEGORIES=	security
MASTER_SITES=	http://pgina.xpasystems.com/files/
DISTNAME=	pgina_pam-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon for allowing a pGina plugin to authenticate against Unix PAM

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		perl5 gmake
USE_PERL5=	run

post-patch:
# PREFIX safeness
# Use correct PAM 'password change' service name
	@${REINPLACE_CMD} -E \
		-e 's|/etc/|${PREFIX}/etc/|' \
		-e 's|passwd|password|' \
		${WRKSRC}/src/pgina_pam_server.c
# {OPENSSL,PERL} location safeness
# PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e 's|/usr/bin/openssl|${OPENSSLBASE}/bin/openssl|' \
		-e 's|/usr/bin/perl|${PERL}|' \
		-e 's|/etc/|${PREFIX}/etc/|' \
		${WRKSRC}/make_cert.pl

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/${DISTNAME:S/-${PORTVERSION}$$//} \
		${STAGEDIR}${PREFIX}/sbin
# share scripts
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/${DISTNAME:S/-${PORTVERSION}$$//}
	@${INSTALL_SCRIPT} ${WRKSRC}/make_cert.pl \
		${STAGEDIR}${PREFIX}/share/${DISTNAME:S/-${PORTVERSION}$$//}
# etc config files
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${DISTNAME:S/-${PORTVERSION}$$//}
	@${INSTALL_DATA} ${WRKSRC}/authasst.conf/* \
		${STAGEDIR}${PREFIX}/etc/${DISTNAME:S/-${PORTVERSION}$$//}

.include <bsd.port.mk>
