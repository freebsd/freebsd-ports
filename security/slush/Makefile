# Ports collection makefile for:  slush
# Date created:			  Sun May 3, 1999
# Whom:                 	shipley@dis.org
#
# $FreeBSD$
#

PORTNAME=	slush
PORTVERSION=	0.1.1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.freebsd.org/pub/FreeBSD/ports/local-distfiles/kris/ \
		http://violet.ibs.com.au/slush/files/ \
		ftp://www.dis.org/pub/Security/

MAINTAINER=	shipley@dis.org

GNU_CONFIGURE=	yes

USE_OPENSSL=	YES

.include <bsd.port.pre.mk>
.if ${OSVERSION} <= 300000
BROKEN=		does not build
.endif

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/control.txt ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/HISTORY ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/slush
	${INSTALL_MAN} ${WRKSRC}/COPYING ${PREFIX}/share/doc/slush
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/slush ${PREFIX}/bin/slush
	${INSTALL_PROGRAM} ${WRKSRC}/slushd ${PREFIX}/sbin/slushd

.include <bsd.port.post.mk>
