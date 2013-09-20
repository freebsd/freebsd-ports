# Created by: Stefan A. Deutscher (sad@mailaps.org)
# $FreeBSD$

PORTNAME=	renattach
PORTVERSION=	1.2.4
CATEGORIES=	mail
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename or remove certain attachments or kill entire messages


GNU_CONFIGURE=	yes

MAN1=		renattach.1
PORTDOCS=	INSTALL
PLIST_FILES=	bin/renattach etc/renattach.conf.ex

NO_STAGE=	yes
post-extract:
	@${RM} -f ${WRKSRC}/src/getopt*

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${DOCSDIR}
	@${ECHO_MSG} "===================="
	@${ECHO_MSG} "Check with ${DOCSDIR}/INSTALL"
	@${ECHO_MSG} "After that you may need to adjust renattach.conf to your needs"
.endif

.include <bsd.port.mk>
