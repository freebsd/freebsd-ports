# Created by: Mij <mij@bitchx.it>
# $FreeBSD$

PORTNAME=	sshguard
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF/sshguard/sshguard/${PORTVERSION}

MAINTAINER=	dan.mcgregor@usask.ca
COMMENT=	Protect hosts from brute-force attacks against SSH and other services

LICENSE=	BSD2CLAUSE

USE_RC_SUBR=	sshguard
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|%PREFIX%|${PREFIX}|' ${WRKSRC}/doc/sshguard.8.rst
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' ${WRKSRC}/examples/sshguard.conf.sample

post-install:
	${INSTALL} -d ${STAGEDIR}${PREFIX}/etc
	${INSTALL} -m 644 ${WRKSRC}/examples/sshguard.conf.sample ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
