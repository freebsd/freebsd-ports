# Created by: johans
# $FreeBSD$

PORTNAME=	signing-party
PORTVERSION=	1.1.9
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/signing-party/ \
		${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/s/signing-party
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Various OpenPGP related tools

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		p5-Net-IDN-Encode>=0:${PORTSDIR}/textproc/p5-Net-IDN-Encode \
		p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-GnuPG-Interface>=0:${PORTSDIR}/security/p5-GnuPG-Interface \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Convert-Recode>=0:${PORTSDIR}/converters/p5-Convert-Recode \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD

CONFLICTS_INSTALL=sig2dot-[0-9]* springgraph-[0-9]*

USES=		perl5 gmake shebangfix
SHEBANG_FILES=	${SCRIPTS}
NO_WRKSUBDIR=	yes

BINS=		keyanalyze/keyanalyze keyanalyze/process_keys
SCRIPTS=	caff/caff caff/pgp-clean caff/pgp-fixkey gpglist/gpglist \
		gpgsigs/gpgsigs gpg-key2ps/gpg-key2ps \
		gpg-mailkeys/gpg-mailkeys keylookup/keylookup \
		sig2dot/sig2dot springgraph/springgraph \
		gpgparticipants/gpgparticipants
MANUALS1=	${SCRIPTS:S/$/.1/} ${BINS:S/$/.1/}
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
	@${INSTALL_PROGRAM} ${BINS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${MANUALS1:S|^|${WRKSRC}/|} \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/caff
	@${INSTALL_DATA} ${WRKSRC}/caff/README* ${STAGEDIR}${DOCSDIR}/caff

.include <bsd.port.mk>
