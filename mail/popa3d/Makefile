# New ports collection makefile for:	popa3d
# Date created:		Sun Feb  6 12:31:29 MSK 2000
# Whom:			Sergey Samoyloff <gonza@techline.ru>
#
# $FreeBSD$
#

PORTNAME=	popa3d
PORTVERSION=	0.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.openwall.com/popa3d/ \
		ftp://ftp.openwall.com/popa3d/ \
		ftp://ftp.dataforce.net/pub/solar/ \
		ftp://ftp.false.com/pub/security/popa3d/
.if defined(SMTP_AFTER_POP3)
PKGNAMESUFFIX?=	-before-sendmail
.endif

MAINTAINER=	dinoex@FreeBSD.org

ALL_TARGET=	popa3d
CFLAGS+=	-DPREFIX=${PREFIX}

.if defined(SMTP_AFTER_POP3)
EXTRA_PATCHES+=	${FILESDIR}/pop-before-sendmail.patch
PLIST=		${WRKDIR}/.PLIST.more

pre-configure:
	@${ECHO} "%%PORTDOCS%%share/doc/popa3d/POPAUTH" >${PLIST}
	@${CAT} ${PKGDIR}/pkg-plist >>${PLIST}
	@${ECHO} "share/sendmail/cf/hack/popauth.m4" >>${PLIST}

post-patch:
	@${PERL5} -pi -e "s=db1/db.h=db.h=" ${WRKSRC}/pop_root.c
.endif

pre-patch:
	@${PERL5} -pi -e "s=/var/empty=${PREFIX}/empty=" ${WRKSRC}/params.h

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${PREFIX}/empty

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 500 \
	    ${WRKSRC}/popa3d ${PREFIX}/libexec/popa3d
.if defined(SMTP_AFTER_POP3)
	${INSTALL_DATA} ${FILESDIR}/popauth.m4 ${CFDIR}/hack
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
