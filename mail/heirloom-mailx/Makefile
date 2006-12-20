# New ports collection makefile for:	nail
# Date created:				20 October 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mailx
PORTVERSION=	12.1
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	heirloom
PKGNAMEPREFIX=	${MASTER_SITE_SUBDIR}-

MAINTAINER=	ports@logvinov.com
COMMENT=	BSD mail utility with MIME, IMAP, POP3, SMTP, and S/MIME extensions

USE_BZIP2=	yes
USE_ICONV=	yes
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		IPv6="-DHAVE_IPv6_FUNCS"

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

PLIST_FILES=	bin/${PORTNAME} \
		"@unexec if cmp -s %D/etc/nail.rc %D/etc/nail.rc.default; then ${RM} -f %D/etc/nail.rc; fi " \
		"etc/nail.rc.default" \
		"@exec [ -f %B/nail.rc ] || ${CP} %B/%f %B/nail.rc"

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc/nail.rc.default
.if !exists(${PREFIX}/etc/nail.rc)
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
