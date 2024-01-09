PORTNAME=	mailx
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	PORTS_JP
DISTFILES=	mail-2.2.8.tar.gz mailx-memo-2.2.8R
EXTRACT_ONLY=	mail-2.2.8.tar.gz

PATCH_SITES=	PORTS_JP
PATCHFILES=	mailx.v05.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail command with mailx extensions

LICENSE=	BSD4CLAUSE

USES=		perl5
USE_PERL5=	run build patch

CONFLICTS=	heirloom-mailx

WRKSRC=		${WRKDIR}/mail-2.2.8

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	${PERL5} -pi.bak -e 's/^(\.Nm mail)/$$1x/i; s/^(\.Dt MAIL)/$$1X/' \
		${WRKSRC}/mail.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mail ${STAGEDIR}${PREFIX}/bin/mailx
	${INSTALL_MAN} ${WRKSRC}/mail.1.gz \
		${STAGEDIR}${PREFIX}/share/man/man1/mailx.1.gz
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/mailx
	${INSTALL_DATA} ${DISTDIR}/mailx-memo-2.2.8R \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
