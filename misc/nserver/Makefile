# ports collection makefile for:	nserver
# Date created:			7 August 2003
# Whom:				Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nserver
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://www.version6.net/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nserver for the Nokia 9000 and 9110 Communicator
# Original site http://www.users.globalnet.co.uk/~syrinx/9110/nserver.html
# doesn't exist anymore

USE_GMAKE=	yes

PLIST_FILES=	sbin/nserver
.ifndef(NOPORTDOCS)
PLIST_FILES+=	share/doc/nserver/README
PLIST_DIRS=	share/doc/nserver
.endif

.include <bsd.port.pre.mk>

OPSYS=		BSD

do-patch:
	@${REINPLACE_CMD} -e "s|-O2|${CFLAGS}|g; \
		s|ttyS3|cuaa0|g; \
		s|= LINUX|= BSD|g; \
		s|^CC|#CC|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nserver ${PREFIX}/sbin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
