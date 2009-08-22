# New ports collection makefile for:	qmail-auditor
# Date created:		2007-02-08
# Whom:			Patrick Tracanelli <eksffa@freebsdbrasil.com.br>
#
# $FreeBSD$
#

PORTNAME=	qmail-auditor
PORTVERSION=	0.47
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www6.freebsdbrasil.com.br/~eksffa/l/qmail-auditor/

MAINTAINER=	eksffa@freebsdbrasil.com.br
COMMENT=	Selective e-mail auditing for qmail by means of qmail-queue wrapping

WRKSRC=		${WRKDIR}/${PORTNAME:R}

USE_QMAIL_RUN=	yes
GNU_CONFIGURE=	yes

SUB_FILES=	pkg-message
SUB_LIST=	QMAIL_PREFIX=${QMAIL_PREFIX}

PLIST_FILES=	bin/qmail-auditor

PORTDOCS=	README

INSTALL_TARGET=	perm

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|@prefix@|g' \
	${WRKSRC}/src/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
