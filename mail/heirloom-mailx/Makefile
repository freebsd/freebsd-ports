PORTNAME=	mailx
PORTVERSION=	12.4
PORTREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	SF/heirloom/heirloom-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	heirloom-

MAINTAINER=	cy@FreeBSD.org
COMMENT=	BSD mail utility with MIME, IMAP, POP3, SMTP, and S/MIME extensions
WWW=		https://heirloom.sourceforge.net/mailx.html

LICENSE=	BSD4CLAUSE

OPTIONS_DEFINE=	IPV6 DOCS

CONFLICTS=	mailx

MAKE_JOBS_UNSAFE=	yes
USES=		cpe iconv localbase ssl tar:bzip2
CPE_VENDOR=	heirloom
CPPFLAGS+=	-DOPENSSL_NO_SSL2
MAKE_ARGS=	PREFIX="${PREFIX}" \
		SYSCONFDIR="${PREFIX}/etc" \
		SENDMAIL="/usr/sbin/sendmail" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PORTDOCS=	AUTHORS COPYING ChangeLog README TODO

IPV6_MAKE_ARGS=	-IPv6="-DHAVE_IPv6_FUNCS"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${WRKSRC}/nail.rc ${STAGEDIR}${PREFIX}/etc/nail.rc.sample

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
