# New ports collection makefile for:	solidpop3d
# Date created:		22 May 2000
# Whom:			Marco Rodrigues <drkangel@drkangel.org>
#
# $FreeBSD$
#

PORTNAME=	solidpop3d
PORTVERSION=	0.15
CATEGORIES=	mail
MASTER_SITES=	http://solidpop3d.pld.org.pl/ \
		ftp://207.176.230.192/

MAINTAINER=	drkangel@drkangel.org

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lmd"

MAN1=		pop_auth.1
MAN5=		spop3d.conf.5 dot-spop3d.5
MAN8=		spop3d.8

post-extract:
	${RM} ${WRKSRC}/src/md5.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/spop3d ${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/man/pop_auth.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/spop3d.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/dot-spop3d.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/spop3d.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/config.example ${PREFIX}/etc/spop3d.conf.sample

.include <bsd.port.mk>
