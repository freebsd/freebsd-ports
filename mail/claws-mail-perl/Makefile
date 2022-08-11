PORTNAME=	perl

COMMENT=	Perl filtering plugin for Claws Mail

USES+=		perl5 shebangfix
SHEBANG_FILES=	src/plugins/perl/tools/matcherrc2perlfilter.pl

PLIST_FILES+=	share/claws-mail/matcherrc2perlfilter.pl

CLAWS_PLUGINS_BUILD=	${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/claws-mail
	${INSTALL_SCRIPT} ${WRKSRC}/src/plugins/perl/tools/matcherrc2perlfilter.pl \
		${STAGEDIR}${PREFIX}/share/claws-mail

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
