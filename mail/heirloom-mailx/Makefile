# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mailx
PORTVERSION=	12.4
PORTREVISION=	4
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/heirloom/heirloom-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	heirloom-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	BSD mail utility with MIME, IMAP, POP3, SMTP, and S/MIME extensions

OPTIONS_DEFINE=	IPV6 DOCS

CONFLICTS=	mailx-[0-9]*

MAKE_JOBS_UNSAFE=	yes
USES=		iconv tar:bzip2
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	IPv6="-DHAVE_IPv6_FUNCS"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${STAGEDIR}${PREFIX}/etc/nail.rc.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
