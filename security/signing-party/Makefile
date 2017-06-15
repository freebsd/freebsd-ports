# Created by: johans
# $FreeBSD$

PORTNAME=	signing-party
PORTVERSION=	2.5
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/signing-party/ \
		DEBIAN
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Various OpenPGP related tools

RUN_DEPENDS=	gpg:security/gnupg \
		p5-Net-IDN-Encode>=0:textproc/p5-Net-IDN-Encode \
		p5-Class-MethodMaker>=0:devel/p5-Class-MethodMaker \
		p5-GnuPG-Interface>=0:security/p5-GnuPG-Interface \
		p5-Mail-Tools>=0:mail/p5-Mail-Tools \
		p5-MIME-Tools>=0:mail/p5-MIME-Tools \
		p5-Convert-Recode>=0:converters/p5-Convert-Recode \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-Template>=0:textproc/p5-Text-Template \
		p5-GD>=0:graphics/p5-GD

CONFLICTS_INSTALL=sig2dot-[0-9]* springgraph-[0-9]*

USES=		perl5 python gmake shebangfix
SHEBANG_FILES=	${SCRIPTS}
NO_WRKSUBDIR=	yes

BINS=		keyanalyze/keyanalyze keyanalyze/process_keys \
		gpgwrap/bin/gpgwrap
SCRIPTS=	caff/caff caff/pgp-clean caff/pgp-fixkey \
		gpgdir/gpgdir gpglist/gpglist \
		gpgparticipants/gpgparticipants gpgsigs/gpgsigs \
		gpg-key2latex/gpg-key2latex \
		gpg-key2ps/gpg-key2ps gpg-mailkeys/gpg-mailkeys \
		keyart/keyart keylookup/keylookup \
		sig2dot/sig2dot springgraph/springgraph \
		gpgparticipants/gpgparticipants
MANUALS1=	${SCRIPTS:S/$/.1/:S/keyart/&\/doc/} ${BINS:S/$/.1/:S/bin/doc/}
EXAMPLES=	caff/caffrc.sample gpg-mailkeys/example.gpg-mailkeysrc
PORTEXAMPLES=	${EXAMPLES:T}

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/doc/signing-party/caff/caffrc\.sample|${EXAMPLESDIR}/caffrc.sample|' \
		${WRKSRC}/caff/caff
	@${REINPLACE_CMD} -e 's|/usr/bin/pinentry-gtk-2|${LOCALBASE}/bin/pinentry-gtk-2|' \
		${WRKSRC}/caff/README.gpg-agent
	@${REINPLACE_CMD} -e 's|[[:<:]]make|${MAKE_CMD}|' \
			-e '/^all/s|pgpring/pgpring||' \
		${WRKSRC}/gpgwrap/Makefile \
		${WRKSRC}/keyanalyze/Makefile
	@${REINPLACE_CMD} -e 's|gcc|${CC}|' ${WRKSRC}/gpgwrap/src/Makefile

do-install:
	${INSTALL_PROGRAM} ${BINS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MANUALS1:S|^|${WRKSRC}/|} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README* ${STAGEDIR}${DOCSDIR}/caff

.include <bsd.port.mk>
