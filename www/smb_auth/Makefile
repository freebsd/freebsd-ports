# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	smb_auth
PORTVERSION=	0.05
PORTREVISION=	5
CATEGORIES=	www
MASTER_SITES=	LOCAL/dinoex

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Proxy authentication module against an SMB server

.if !defined(WITHOUT_REGISTER_SAMBA)
RUN_DEPENDS=	${LOCALBASE}/sbin/smbd:${SAMBA_PORT}
.endif

ALL_TARGET=	smb_auth
SAMBA_PORT?=	net/samba36

OPTIONS_DEFINE=	DOCS

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/smb_auth ${STAGEDIR}${PREFIX}/bin/
		${INSTALL_SCRIPT} ${WRKSRC}/smb_auth.sh ${STAGEDIR}${PREFIX}/bin/

do-install-DOCS-on:
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${FILESDIR}/README ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
