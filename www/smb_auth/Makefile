# New ports collection makefile for:	smb_auth
# Date created:				13 January 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smb_auth
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.hacom.nl/~richard/software/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	A proxy authentication module against an SMB server

.if !defined(WITHOUT_REGISTER_SAMBA)
RUN_DEPENDS=	${LOCALBASE}/sbin/smbd:${PORTSDIR}/${SAMBA_PORT}
.endif

ALL_TARGET=	smb_auth
SAMBA_PORT?=	net/samba

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/smb_auth ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/smb_auth.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${FILESDIR}/README ${DOCSDIR}/
.endif

post-install:
		@${ECHO_MSG}
		@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
		@${ECHO_MSG} '  Refer to ${PREFIX}/share/doc/smb_auth/README on how to configure smb_auth.'
		@${ECHO_MSG}
		@${ECHO_MSG} '  NOTE: For smb_auth to work properly you must set debug level>0 in your'
		@${ECHO_MSG} '        smb.conf file.'
		@${ECHO_MSG} ' +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'
		@${ECHO_MSG}

.include <bsd.port.mk>
