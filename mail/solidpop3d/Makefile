# New ports collection makefile for:	solidpop3d
# Date created:		22 May 2000
# Whom:			Marco Rodrigues <drkangel@drkangel.org>
#
# $FreeBSD$
#

PORTNAME=	solidpop3d
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	mail ipv6
MASTER_SITES=	http://solidpop3d.pld.org.pl/ \
		ftp://207.176.230.192/
DISTNAME=	solid-pop3d-${PORTVERSION}

MAINTAINER=	drkangel@drkangel.org
COMMENT=	SolidPop3 POP3 daemon (fully RFC1939 compliant)

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-pam --enable-apop --enable-bulletins \
		--enable-last --enable-mapping --enable-nonip --enable-connect
CONFIGURE_ENV=	LDFLAGS="-lmd"

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
CONFIGURE_ARGS+=	--enable-ipv6
.endif

MAN1=		pop_auth.1
MAN5=		spop3d.conf.5 dot-spop3d.5
MAN8=		spop3d.8

post-extract:
	${RM} ${WRKSRC}/src/md5.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/spop3d ${PREFIX}/libexec
	${INSTALL_PROGRAM} ${WRKSRC}/src/pop_auth ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/pop_auth.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/man/spop3d.conf.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/dot-spop3d.5 ${PREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/spop3d.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/doc/config.example ${PREFIX}/etc/spop3d.conf.sample
	${MKDIR} /var/spool/spop3d

.include <bsd.port.post.mk>
