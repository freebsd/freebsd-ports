# Created by: Greg Hewgill <greg@hewgill.com>
# $FreeBSD$

PORTNAME=	zebedee
PORTVERSION=	2.5.3
CATEGORIES=	security
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Encrypted, secure compressed TCP tunnel

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL2.txt

USES=		perl5
USE_OPENSSL=	yes
USE_PERL5=	build

PORTEXAMPLES=	vncviewer.zbd vncserver.zbd server.key server.id client1.key \
		client2.key clients.id
PORTDOCS=	README.txt CHANGES.txt zebedee.html ftpgw.tcl.html

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} \
		-e 's| gcc| ${CC}|' \
		${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zebedee ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ftpgw.tcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/zebedee.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ftpgw.tcl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/server.zbd ${STAGEDIR}${PREFIX}/etc/server.zbd.sample

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for e in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${e} ${STAGEDIR}${EXAMPLESDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for d in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${d} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
