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

MAKE_ARGS+=	mandir=${MANPREFIX}/man prefix=${PREFIX}
MASTERDIR=	${.CURDIR}/../notmuch
NO_ARCH=	yes
WRKSRC_SUBDIR=	contrib/notmuch-mutt

OPTIONS_DEFINE=	EXAMPLES MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${MV} ${STAGEDIR}${PREFIX}/etc/Muttrc.d/notmuch-mutt.rc ${STAGEDIR}${EXAMPLESDIR}/notmuch-mutt.rc
	@${RMDIR} ${STAGEDIR}${PREFIX}/etc/Muttrc.d

post-install-EXAMPLES-off:
	@${RM} -r ${STAGEDIR}${PREFIX}/etc/Muttrc.d

post-install-MANPAGES-off:
	@${RM} ${STAGEDIR}${MANPREFIX}/man/man1/notmuch-mutt.1

.include "${MASTERDIR}/Makefile"
