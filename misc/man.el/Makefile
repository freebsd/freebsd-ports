PORTNAME=	i18n-man
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	misc elisp
MASTER_SITES=	ftp://daemon.jp.freebsd.org/pub/FreeBSD-jp/man-jp/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Browse I18N capable UNIX manual pages with Mule, Emacs, and XEmacs

# If you use Japanese manuals, install japanese/man as well.

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ELISPDIR=	${PREFIX}/share/emacs/site-lisp

do-install:
	@${MKDIR} ${STAGEDIR}${ELISPDIR} ${STAGEDIR}${PREFIX}/share/doc/i18n-man
	@(cd ${WRKSRC}; \
		${INSTALL_DATA} `${TAR} tzf ${DISTDIR}/${DISTFILES}` \
			${STAGEDIR}${ELISPDIR})
	${INSTALL_SCRIPT} ${FILESDIR}/byte-compile \
		${STAGEDIR}${PREFIX}/share/doc/i18n-man

.include <bsd.port.mk>
