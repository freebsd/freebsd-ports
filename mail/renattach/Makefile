# New ports collection makefile for:	renattach
# Date created:				20 June 2004
# Whom:					Stefan A. Deutscher (sad@mailaps.org)
#
# $FreeBSD$
#

PORTNAME=	renattach
PORTVERSION=	1.2.1
CATEGORIES=	mail
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename or remove certain attachments or kill entire messages

GNU_CONFIGURE=	yes

MAN1=		renattach.1
PLIST_FILES=	bin/renattach etc/renattach.conf.ex
PORTDOCS=	INSTALL

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTDOCS}  ${DOCSDIR}
.endif
	@${ECHO_MSG} "===================="
	@${ECHO_MSG} "Check with ${DOCSDIR}/INSTALL"
	@${ECHO_MSG} "After that you may need to adjust renattach.conf to your needs"

.include <bsd.port.mk>
