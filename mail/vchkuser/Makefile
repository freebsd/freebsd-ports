# New ports collection makefile for:	vchkuser
# Date created:			23 January 2008
# Whom:				Luiz Otavio O Souza <loos.br@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	vchkuser
PORTVERSION=	0.2
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	loos.br@gmail.com
COMMENT=	Qmail-smtpd+vpopmail check rcpt to on the fly

PLIST_FILES=	vpopmail/bin/vchkuser

BUILD_DEPENDS+=	${VPOPMAILDIR}/lib/libvpopmail.a:${PORTSDIR}/mail/vpopmail

USE_QMAIL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
VPOPMAILDIR?=	${PREFIX}/vpopmail

DOCS=		README CHANGELOG

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/

PLIST_FILES+=	${DOCSDIR_REL}/README ${DOCSDIR_REL}/CHANGELOG
PLIST_DIRS=	${DOCSDIR_REL}
.endif

.include <bsd.port.mk>
