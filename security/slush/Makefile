# Ports collection makefile for:  slush
# Date created:			  Sun May 3, 1999
# Whom:                 	shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	slush
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PACKETSTORM}
MASTER_SITE_SUBDIR=	crypt/SSL/slush

MAINTAINER=	shipley@dis.org
COMMENT=	A telnet-like application which uses a secure SSL channel

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

.include <bsd.port.pre.mk>
.if ${OSVERSION} <= 300000
BROKEN=		does not build
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/control.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/slush ${PREFIX}/bin/slush
	${INSTALL_PROGRAM} ${WRKSRC}/slushd ${PREFIX}/sbin/slushd

.include <bsd.port.post.mk>
