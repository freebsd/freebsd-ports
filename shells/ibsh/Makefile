# New ports collection makefile for:	ibsh
# Date created:				1 Oct 2005
# Whom:					Vaida Bogdan
#
# $FreeBSD$
#

PORTNAME=	ibsh
PORTVERSION=	0.3e
CATEGORIES=	shells
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	vaida.bogdan@gmail.com
COMMENT=	Restricted unix shell

USE_GMAKE=	yes
ALL_TARGET=	ibsh
INSTALL_TARGET=	ibsh_install

SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS BUGS CONTRIBUTORS COPYING COPYRIGHT ChangeLog \
		INSTALL README TODO VERSION

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|PATH_MAX|PATH_MAXb|g' ${WRKSRC}/delbadfiles.c ${WRKSRC}/ibsh.h
	@${REINPLACE_CMD} -e 's|/etc/ibsh|${PREFIX}/etc/ibsh|g' ${WRKSRC}/ibsh.h

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${ECHO}
	@${CAT} ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.post.mk>
