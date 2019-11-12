# Created by: johans
# $FreeBSD$

PORTNAME=	signing-party
PORTVERSION=	2.10
CATEGORIES=	security

MAINTAINER=	romain@FreeBSD.org
COMMENT=	Various OpenPGP related tools

LICENSE=	BSD2CLAUSE BSD3CLAUSE GPLv2 GPLv2+ GPLv3+ MIT
LICENSE_COMB=	multi

BUILD_DEPENDS=	gsed:textproc/gsed
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

USES=		perl5 python gmake shebangfix
SHEBANG_FILES=	${SCRIPTS}
BINARY_ALIAS=	sed=gsed
CONFLICTS_INSTALL=sig2dot-[0-9]* springgraph-[0-9]*

USE_GITLAB=	yes
GL_SITE=	https://salsa.debian.org/
GL_ACCOUNT=	signing-party-team
GL_COMMIT=	8f6c9d59d8edbb08dade7bac06417fce07626f7f

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

OPTIONS_DEFINE=	DOCS EXAMPLES

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
