# Created by: Greg Hewgill <greg@hewgill.com>
# $FreeBSD$

PORTNAME=	zebedee
PORTVERSION=	2.5.3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypted, secure compressed TCP tunnel

USES=		perl5
USE_OPENSSL=	yes
USE_PERL5=	build

EXAMPLES=	vncviewer.zbd vncserver.zbd server.key server.id client1.key \
		client2.key clients.id
DOCS=		README.txt LICENCE.txt CHANGES.txt zebedee.html ftpgw.tcl.html

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's| gcc| ${CC}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zebedee ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftpgw.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zebedee.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ftpgw.tcl.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/server.zbd ${STAGEDIR}${PREFIX}/etc/server.zbd.sample
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
