# New ports collection makefile for:	renattach
# Date created:				20 June 2004
# Whom:					Stefan A. Deutscher (sad@mailaps.org)
#
# $FreeBSD$
#

PORTNAME=	renattach
PORTVERSION=	1.2.2
CATEGORIES=	mail
MASTER_SITES=	http://www.pc-tools.net/files/unix/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rename or remove certain attachments or kill entire messages

USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		renattach.1
PORTDOCS=	INSTALL
PLIST_FILES=	bin/renattach etc/renattach.conf.ex

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
