# New ports collection makefile for:	zebedee
# Date created:		4 January 2000
# Whom:			Greg Hewgill <greg@hewgill.com>
#
# $FreeBSD$
#

PORTNAME=	zebedee
PORTVERSION=	2.2.2
CATEGORIES=	security
MASTER_SITES=	http://www.winton.org.uk/zebedee/ \
		http://www.hewgill.com/zebedee/

MAINTAINER=	greg@hewgill.com

.if defined(${BATCH}) || !exists(/usr/bin/bzip2)
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_OPENSSL=	YES
USE_PERL5=	yes

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}

MAN1=		zebedee.1 ftpgw.tcl.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zebedee ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftpgw.tcl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zebedee.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ftpgw.tcl.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/server.zbd ${PREFIX}/etc/server.zbd.sample
	${MKDIR} ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/vncviewer.zbd ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/vncserver.zbd ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/server.key ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/server.id ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/client1.key ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/client2.key ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/clients.id ${PREFIX}/share/examples/zebedee
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/zebedee.html ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/ftpgw.tcl.html ${PREFIX}/share/doc/zebedee
.endif

.include <bsd.port.mk>
