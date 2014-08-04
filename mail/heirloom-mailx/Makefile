# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mailx
PORTVERSION=	12.4
PORTREVISION=	5
CATEGORIES=	mail ipv6
MASTER_SITES=	SF/heirloom/heirloom-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	heirloom-

MAINTAINER=	jamie@dyslexicfish.net
COMMENT=	BSD mail utility with MIME, IMAP, POP3, SMTP, and S/MIME extensions

OPTIONS_DEFINE=		IPV6 DOCS SENDMAIL_PORT
SENDMAIL_PORT_DESC=	Use sendmail from ports instead of base

CONFLICTS=	mailx-[0-9]*

MAKE_JOBS_UNSAFE=	yes
USES=		iconv tar:bzip2
USE_OPENSSL=	yes
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	IPv6="-DHAVE_IPv6_FUNCS"
.endif

.if ${PORT_OPTIONS:MSENDMAIL_PORT}
MAKE_ARGS+=	SENDMAIL="${LOCALBASE}/sbin/sendmail"
RUN_DEPENDS=	${LOCALBASE}/sbin/sendmail:${PORTSDIR}/mail/sendmail
.else
MAKE_ARGS+=	SENDMAIL="/usr/sbin/sendmail"
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
