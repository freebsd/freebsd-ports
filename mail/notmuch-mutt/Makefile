# $FreeBSD$

CATEGORIES=	mail
PKGNAMESUFFIX=	-mutt

COMMENT=	Integrates the Notmuch email search and tagging application with Mutt

RUN_DEPENDS=	mutt:mail/mutt \
		notmuch:mail/notmuch \
		p5-Mail-Box>0:mail/p5-Mail-Box \
		p5-Mail-Tools>0:mail/p5-Mail-Tools \
		p5-String-ShellQuote>0:textproc/p5-String-ShellQuote \
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu

USES=		gmake perl5

MASTERDIR=	${.CURDIR}/../notmuch
NO_ARCH=	yes
WRKSRC_SUBDIR=	contrib/notmuch-mutt

OPTIONS_DEFINE=	EXAMPLES MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/notmuch-mutt ${STAGEDIR}${PREFIX}/bin

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/notmuch-mutt.rc ${STAGEDIR}${EXAMPLESDIR}/notmuch-mutt.rc

do-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/notmuch-mutt.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include "${MASTERDIR}/Makefile"
