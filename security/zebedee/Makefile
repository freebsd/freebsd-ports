# New ports collection makefile for:	zebedee
# Version required:	1.2.0
# Date created:		4 January 2000
# Whom:			Greg Hewgill <greg@hewgill.com>
#
# $FreeBSD$
#

DISTNAME=	zebedee-1.2.0
CATEGORIES=	security
MASTER_SITES=	http://www.winton.org.uk/zebedee/ \
		http://www.hewgill.com/zebedee/

MAINTAINER=	greg@hewgill.com

BUILD_DEPENDS=	${LOCALBASE}/include/openssl/blowfish.h:${PORTSDIR}/security/openssl \
		${LOCALBASE}/lib/libcrypto.a:${PORTSDIR}/security/openssl \
		${LOCALBASE}/lib/libbz2.a:${PORTSDIR}/archivers/bzip2

USE_PERL5=	yes

MAN1=		zebedee.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zebedee ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zebedee.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/server.zbd ${PREFIX}/etc/server.zbd.sample
	${MKDIR} ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/vncviewer.zbd ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/vncserver.zbd ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/server.key ${PREFIX}/share/examples/zebedee
	${INSTALL_DATA} ${WRKSRC}/server.id ${PREFIX}/share/examples/zebedee
	${MKDIR} ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/LICENCE.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/CHANGES.txt ${PREFIX}/share/doc/zebedee
	${INSTALL_DATA} ${WRKSRC}/zebedee.html ${PREFIX}/share/doc/zebedee

.include <bsd.port.mk>
