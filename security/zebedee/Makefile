# New ports collection makefile for:	zebedee
# Date created:		4 January 2000
# Whom:			Greg Hewgill <greg@hewgill.com>
#
# $FreeBSD$
#

PORTNAME=	zebedee
PORTVERSION=	2.5.2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.winton.org.uk/zebedee/ \
		http://www.hewgill.com/zebedee/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	greg@hewgill.com
COMMENT=	Encrypted, secure compressed TCP tunnel

.if defined(${BATCH}) || !exists(/usr/bin/bzip2)
LIB_DEPENDS=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_OPENSSL=	YES
USE_PERL5=	yes

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \

MAN1=		zebedee.1 ftpgw.tcl.1

EXAMPLES=	vncviewer.zbd vncserver.zbd server.key server.id client1.key \
		client2.key clients.id
DOCS=		README.txt LICENCE.txt CHANGES.txt zebedee.html ftpgw.tcl.html

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zebedee ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftpgw.tcl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zebedee.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ftpgw.tcl.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/server.zbd ${PREFIX}/etc/server.zbd.sample
	${MKDIR} ${EXAMPLESDIR}
.for e in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${e} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
