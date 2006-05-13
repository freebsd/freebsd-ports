# New ports collection makefile for:	pam_pGina
# Date created:		Thu Apr 29 16:03:45 UTC 2004
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pam_pGina
PORTVERSION=	1.1.3
CATEGORIES=	security
MASTER_SITES=	http://pgina.xpasystems.com/files/
DISTNAME=	pgina_pam-${PORTVERSION}

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Daemon for allowing a pGina plugin to authenticate against Unix PAM

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_PERL5_RUN=	yes

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
		${PREFIX}/sbin
# share scripts
	@${MKDIR} ${PREFIX}/share/${DISTNAME:S/-${PORTVERSION}$$//}
	@${INSTALL_SCRIPT} ${WRKSRC}/make_cert.pl \
		${PREFIX}/share/${DISTNAME:S/-${PORTVERSION}$$//}
# etc config files
	@${MKDIR} ${PREFIX}/etc/${DISTNAME:S/-${PORTVERSION}$$//}
	@${INSTALL_DATA} ${WRKSRC}/authasst.conf/* \
		${PREFIX}/etc/${DISTNAME:S/-${PORTVERSION}$$//}

.include <bsd.port.mk>
