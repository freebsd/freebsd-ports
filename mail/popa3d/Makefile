# Created by: Sergey Samoyloff <gonza@techline.ru>
# $FreeBSD$

PORTNAME=	popa3d
PORTVERSION=	1.0.3
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/
PKGNAMESUFFIX?=	${SMTP_AFTER_POP3_SUFFIX}${STANDALONE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Secure, performance, tiny POP3 daemon

ALL_TARGET=	popa3d
PLIST=		${WRKDIR}/.PLIST.more
CFLAGS+=	-DPREFIX=${PREFIX}
UNIQUENAME=	${.CURDIR:T}

OPTIONS_DEFINE=	SMTP_AFTER_POP3 STANDALONE_POP3 SETPROCTITLE
NO_OPTIONS_SORT=yes
SMTP_AFTER_POP3_DESC=Enable SMTP-after-POP support
STANDALONE_POP3_DESC=Enable standalone server mode
SETPROCTITLE_DESC=Enable setproctitle() support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSTANDALONE_POP3}
STANDALONE_SUFFIX=	-standalone
PLIST_SUB+=	STANDALONE_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-before-sendmail-0.*
USE_RC_SUBR=	popa3d
PKGMESSAGE=	${NONEXISTENT}
PKGDEINSTALL=	${NONEXISTENT}
.else
SUB_FILES=	pkg-message
PLIST_SUB+=	STANDALONE_POP3="@comment "
.endif

.if ${PORT_OPTIONS:MSMTP_AFTER_POP3}
SMTP_AFTER_POP3_SUFFIX=	-before-sendmail
EXTRA_PATCHES+=	${FILESDIR}/pop-before-sendmail.patch
PLIST_SUB+=	SMTP_AFTER_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-standalone-0.*
.else
PLIST_SUB+=	SMTP_AFTER_POP3="@comment "
CONFLICTS?=	popa3d-standalone-0.* popa3d-before-sendmail-0.*
.endif

.if ${PORT_OPTIONS:MSETPROCTITLE}
EXTRA_PATCHES+=	${FILESDIR}/setproctitle.patch
.endif

.include <bsd.port.pre.mk>

pre-configure:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !exists(/var/empty)
	@${REINPLACE_CMD} -e "s=/var/empty=${PREFIX}/empty=" \
		${WRKSRC}/params.h
	@${ECHO_CMD} "@exec ${MKDIR} %D/empty" >>${PLIST}
	@${ECHO_CMD} "@dirrm empty" >>${PLIST}
.endif

.if ${PORT_OPTIONS:MSMTP_AFTER_POP3} && !defined(WITHOUT_POPAUTH_M4)
	@${ECHO_CMD} "@cwd ${CFDIR}" >>${PLIST}
	@${ECHO_CMD} "hack/popauth.m4" >>${PLIST}
.endif
.if ${PORT_OPTIONS:MSTANDALONE_POP3}
	@${REINPLACE_CMD} -e 's|^\(#define POP_STANDALONE\).*|\1 1|' \
		${WRKSRC}/params.h
.endif
.if defined(MAILBOX_HOME)
	@${REINPLACE_CMD} -e 's|^#define \(MAIL_SPOOL_PATH\).*|#undef \1|' \
		${WRKSRC}/params.h
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.if !exists(/var/empty)
	@${MKDIR} ${PREFIX}/empty
.endif

do-install:
	${INSTALL} ${COPY} -m 500 \
	    ${WRKSRC}/popa3d ${STAGEDIR}${PREFIX}/libexec/popa3d
	${INSTALL_MAN} ${WRKSRC}/popa3d.8 ${STAGEDIR}${MANPREFIX}/man/man8/
.if ${PORT_OPTIONS:MSMTP_AFTER_POP3} && !defined(WITHOUT_POPAUTH_M4)
	${MKDIR} ${STAGEDIR}${CFDIR}/hack
	${INSTALL_DATA} ${FILESDIR}/popauth.m4 ${STAGEDIR}${CFDIR}/hack/
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${STAGEDIR}${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}/
.if ${PORT_OPTIONS:MSMTP_AFTER_POP3}
	${INSTALL_DATA} ${FILESDIR}/POPAUTH ${STAGEDIR}${DOCSDIR}/
.endif
.endif

.if exists(${LOCALBASE}/share/sendmail/cf/mailer/uucp.m4)
CFDIR=		${LOCALBASE}/share/sendmail/cf
.else
CFDIR=		/usr/share/sendmail/cf
.endif

.include <bsd.port.post.mk>
