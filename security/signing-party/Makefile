# Created by: johans
# $FreeBSD$

PORTNAME=	signing-party
PORTVERSION=	1.1.4
PORTREVISION=	3
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/johans/signing-party/ \
		${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/s/signing-party
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Various OpenPGP related tools

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		p5-Class-MethodMaker>=0:${PORTSDIR}/devel/p5-Class-MethodMaker \
		p5-GnuPG-Interface>=0:${PORTSDIR}/security/p5-GnuPG-Interface \
		p5-Mail-Tools>=0:${PORTSDIR}/mail/p5-Mail-Tools \
		p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools \
		p5-Convert-Recode>=0:${PORTSDIR}/converters/p5-Convert-Recode \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-GD>=0:${PORTSDIR}/graphics/p5-GD

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}

CONFLICTS_INSTALL=sig2dot-[0-9]* springgraph-[0-9]*

REINPLACE_ARGS=	-i ''
USE_GMAKE=	yes
USES=		perl5

SCRIPTS=	caff/caff caff/pgp-clean caff/pgp-fixkey gpglist/gpglist \
		gpgsigs/gpgsigs gpg-key2ps/gpg-key2ps \
		gpg-mailkeys/gpg-mailkeys keylookup/keylookup \
		sig2dot/sig2dot springgraph/springgraph \
		gpgparticipants/gpgparticipants \
		keyanalyze/keyanalyze keyanalyze/process_keys \
		keyanalyze/pgpring/pgppubring
MANUALS1=	${SCRIPTS:S/$/.1/}
EXAMPLES=	caff/caffrc.sample gpg-mailkeys/example.gpg-mailkeysrc

PLIST_FILES=	${SCRIPTS:T:S|^|bin/|} ${EXAMPLES:T:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	*
MAN1=		${MANUALS1:T}

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/doc/signing-party/caff/caffrc\.sample|${EXAMPLESDIR}/caffrc.sample|' \
		${WRKSRC}/caff/caff
	@${REINPLACE_CMD} -e 's|/usr/bin/pinentry-gtk-2|${LOCALBASE}/bin/pinentry-gtk-2|' \
		${WRKSRC}/caff/README.gpg-agent
	@${REINPLACE_CMD} -e 's|make|${GMAKE}|' \
			-e 's|make pgpring|make|' \
		${WRKSRC}/gpgwrap/Makefile \
		${WRKSRC}/keyanalyze/Makefile
	# Rename pgpring to pgppubring to avoid conflict with mail/mutt
	@${REINPLACE_CMD} -e 's|pgpring|pgppubring|g' \
		${WRKSRC}/keyanalyze/pgpring/Makefile.in
	@cd ${WRKSRC}/keyanalyze/pgpring && ${MV} pgpring.1 pgppubring.1

do-install:
	${INSTALL_SCRIPT} ${SCRIPTS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MANUALS1:S|^|${WRKSRC}/|} ${MAN1PREFIX}/man/man1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/caff
	${INSTALL_DATA} ${WRKSRC}/caff/README* ${DOCSDIR}/caff
.endif

.include <bsd.port.mk>
