# New ports collection makefile for:	popa3d
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	popa3d
PORTVERSION=	0.6.4.1
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/
PKGNAMESUFFIX?=	${SMTP_AFTER_POP3_SUFFIX}${STANDALONE_SUFFIX}${PKGNAMESUFFIX2}

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Secure, performance, tiny POP3 daemon

USE_REINPLACE=	yes
ALL_TARGET=	popa3d
MAN8=		popa3d.8
PLIST=		${WRKDIR}/.PLIST.more
CFLAGS+=	-DPREFIX=${PREFIX}
.if defined(STANDALONE_POP3)
STANDALONE_SUFFIX=	-standalone
PLIST_SUB+=	STANDALONE_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-before-sendmail-0.*
PKGMESSAGE=	${NONEXISTENT}
PKGDEINSTALL=	${NONEXISTENT}
.else
PLIST_SUB+=	STANDALONE_POP3="@comment "
.endif
.if defined(SMTP_AFTER_POP3)
SMTP_AFTER_POP3_SUFFIX=	-before-sendmail
EXTRA_PATCHES+=	${FILESDIR}/pop-before-sendmail.patch
PLIST_SUB+=	SMTP_AFTER_POP3=""
CONFLICTS?=	popa3d-0.* popa3d-standalone-0.*
.else
PLIST_SUB+=	SMTP_AFTER_POP3="@comment "
CONFLICTS?=	popa3d-standalone-0.* popa3d-before-sendmail-0.*
.endif

.if defined(STANDALONE_POP3)
post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/popa3d.sh \
		> ${WRKSRC}/popa3d.sh
.endif

pre-configure:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !exists(/var/empty)
	@${REINPLACE_CMD} -e "s=/var/empty=${PREFIX}/empty=" \
		${WRKSRC}/params.h
	@${ECHO_CMD} "@exec ${MKDIR} %D/empty" >>${PLIST}
	@${ECHO_CMD} "@dirrm empty" >>${PLIST}
.endif
.if defined(SMTP_AFTER_POP3)
	@${ECHO_CMD} "@cwd ${CFDIR}" >>${PLIST}
	@${ECHO_CMD} "hack/popauth.m4" >>${PLIST}
.endif
.if defined(STANDALONE_POP3)
	@${REINPLACE_CMD} -e 's|^\(#define POP_STANDALONE\).*|\1 1|' \
		${WRKSRC}/params.h
.endif

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.if !exists(/var/empty)
	@${MKDIR} ${PREFIX}/empty
.endif

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 500 \
	    ${WRKSRC}/popa3d ${PREFIX}/libexec/popa3d
	${INSTALL_MAN} ${WRKSRC}/popa3d.8 ${MANPREFIX}/man/man8/
.if defined(SMTP_AFTER_POP3)
	${INSTALL_DATA} ${FILESDIR}/popauth.m4 ${CFDIR}/hack/
.endif
.if defined(STANDALONE_POP3)
	${INSTALL_DATA} ${WRKSRC}/popa3d.sh ${PREFIX}/etc/rc.d/popa3d.sh-dist
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${DOCSDIR}/
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}/
.if defined(SMTP_AFTER_POP3)
	${INSTALL_DATA} ${FILESDIR}/POPAUTH ${DOCSDIR}/
.endif
.endif

.if !defined(STANDALONE_POP3)
post-install:
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/share/sendmail/cf/mailer/uucp.m4)
CFDIR=		${LOCALBASE}/share/sendmail/cf
.else
CFDIR=		/usr/share/sendmail/cf
.endif

.include <bsd.port.post.mk>
