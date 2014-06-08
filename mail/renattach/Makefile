# Created by: Stefan A. Deutscher (sad@mailaps.org)
# $FreeBSD$

PORTNAME=	renattach
PORTVERSION=	1.2.4
CATEGORIES=	mail
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename or remove certain attachments or kill entire messages


GNU_CONFIGURE=	yes

PORTDOCS=	INSTALL
PLIST_FILES=	bin/renattach etc/renattach.conf.ex man/man1/renattach.1.gz

post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${ECHO_MSG} "===================="
	@${ECHO_MSG} "Check with ${DOCSDIR}/INSTALL"
	@${ECHO_MSG} "After that you may need to adjust renattach.conf to your needs"
.endif

.include <bsd.port.mk>
