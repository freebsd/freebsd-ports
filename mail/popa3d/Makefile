# New ports collection makefile for:	popa3d
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	popa3d
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/pub/projects/popa3d/ \
		ftp://ftp.dataforce.net/pub/solar/
.if defined(SMTP_AFTER_POP3)
PKGNAMESUFFIX?=	-before-sendmail
.endif

MAINTAINER=	dinoex@FreeBSD.org

ALL_TARGET=	popa3d
MAN8=		popa3d.8
PLIST=		${WRKDIR}/.PLIST.more
CFLAGS+=	-DPREFIX=${PREFIX}
.if defined(SMTP_AFTER_POP3)
EXTRA_PATCHES+=	${FILESDIR}/pop-before-sendmail.patch
.endif

pre-configure:
	@${CAT} ${PKGDIR}/pkg-plist >${PLIST}
.if !exists(/var/empty)
	@${ECHO_CMD} "@exec ${MKDIR} %D/empty" >>${PLIST}
	@${ECHO_CMD} "@dirrm empty" >>${PLIST}
.endif
.if defined(SMTP_AFTER_POP3)
	@${ECHO_CMD} "%%PORTDOCS%%share/doc/popa3d/POPAUTH" >>${PLIST}
	@${ECHO_CMD} "@cwd ${CFDIR}" >>${PLIST}
	@${ECHO_CMD} "hack/popauth.m4" >>${PLIST}
.endif

.if defined(SMTP_AFTER_POP3)
post-patch:
	@${MV} ${WRKSRC}/pop_root.c ${WRKSRC}/pop_root.c.sed
	${SED} -e "s=db1/db.h=db.h=" \
		${WRKSRC}/pop_root.c.sed > ${WRKSRC}/pop_root.c
.endif

.if !exists(/var/empty)
pre-patch:
	@${MV} ${WRKSRC}/params.h ${WRKSRC}/params.h.sed
	${SED} -e "s=/var/empty=${PREFIX}/empty=" \
		${WRKSRC}/params.h.sed > ${WRKSRC}/params.h
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
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/DESIGN ${PREFIX}/share/doc/popa3d
	${INSTALL_MAN} ${WRKSRC}/LICENSE ${PREFIX}/share/doc/popa3d
.if defined(SMTP_AFTER_POP3)
	${INSTALL_DATA} ${FILESDIR}/POPAUTH ${PREFIX}/share/doc/popa3d
.endif
.endif

post-install:
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

.if exists(${DESTDIR}/${LOCALBASE}/share/sendmail/cf/mailer/uucp.m4)
CFDIR=		${DESTDIR}${LOCALBASE}/share/sendmail/cf
.else
CFDIR=		${DESTDIR}/usr/share/sendmail/cf
.endif
