# New ports collection makefile for:	smb_auth
# Date created:				13 January 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	smb_auth
PORTVERSION=	0.05
CATEGORIES=	www
MASTER_SITES=	http://www.hacom.nl/~richard/software/

MAINTAINER=	sobomax@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/sbin/squid:${PORTSDIR}/www/squid22 \
		${LOCALBASE}/sbin/smbd:${PORTSDIR}/net/samba

ALL_TARGET=	smb_auth

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/smb_auth ${PREFIX}/bin
		${INSTALL_SCRIPT} ${WRKSRC}/smb_auth.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${PREFIX}/share/doc/smb_auth
		${INSTALL_MAN} ${FILESDIR}/README ${PREFIX}/share/doc/smb_auth
		${INSTALL_MAN} ${WRKSRC}/COPYING-2.0 ${PREFIX}/share/doc/smb_auth
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
