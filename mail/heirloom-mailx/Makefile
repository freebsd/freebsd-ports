# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mailx
PORTVERSION=	12.4
PORTREVISION=	3
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/heirloom/heirloom-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	heirloom-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD mail utility with MIME, IMAP, POP3, SMTP, and S/MIME extensions

OPTIONS_DEFINE=	IPV6 DOCS

CONFLICTS=	mailx-[0-9]*

MAKE_JOBS_UNSAFE=	yes
USE_BZIP2=	yes
USES=		iconv
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		${PORTNAME}.1
PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

PLIST_FILES=	bin/${PORTNAME} \
		"@unexec if cmp -s %D/etc/nail.rc %D/etc/nail.rc.default; then ${RM} -f %D/etc/nail.rc; fi " \
		"etc/nail.rc.default" \
		"@exec [ -f %B/nail.rc ] || ${CP} %B/%f %B/nail.rc"

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	IPv6="-DHAVE_IPv6_FUNCS"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc/nail.rc.default
.if !exists(${PREFIX}/etc/nail.rc)
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${PREFIX}/etc
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
