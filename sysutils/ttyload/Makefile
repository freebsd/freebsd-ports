# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttyload
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.daveltd.com/src/util/ttyload/ \
		http://mirror.mcx2.org/

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Give a color-coded graph of load averages over time

ALL_TARGET=	default

USE_BZIP2=	yes
PLIST_FILES=	bin/ttyload
PORTDOCS=	*
SUB_FILES=	pkg-message

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCSDIR}/LICENSE
.endif

	@${ECHO_MSG} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} ""

.include <bsd.port.mk>
