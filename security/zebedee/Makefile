# New ports collection makefile for:	zebedee
# Date created:		4 January 2000
# Whom:			Greg Hewgill <greg@hewgill.com>
#
# $FreeBSD$
#

PORTNAME=	zebedee
PORTVERSION=	2.5.3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypted, secure compressed TCP tunnel

USE_OPENSSL=	YES
USE_PERL5_BUILD=YES

MAKE_ENV+=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS} \

MAN1=		zebedee.1 ftpgw.tcl.1

EXAMPLES=	vncviewer.zbd vncserver.zbd server.key server.id client1.key \
		client2.key clients.id
DOCS=		README.txt LICENCE.txt CHANGES.txt zebedee.html ftpgw.tcl.html

post-patch:
	@${REINPLACE_CMD} \
		-e 's| gcc| ${CC}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

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
