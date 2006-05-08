# New ports collection makefile for:	signing-party
# Date created:				13 September 2005
# Whom:					johans
#
# $FreeBSD$
#

PORTNAME=	signing-party
PORTVERSION=	0.4.6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/s/signing-party
DISTNAME=	${PORTNAME}_${PORTVERSION:R}.orig

PATCH_SITES=	${MASTER_SITES}
PATCH_SITE_SUBDIR=	${MASTER_SITE_SUBDIR}
PATCHFILES=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	johans@stack.nl
COMMENT=	Various OpenPGP related tools

RUN_DEPENDS=	gpg:${PORTSDIR}/security/gnupg \
		${SITE_PERL}/GnuPG/Interface.pm:${PORTSDIR}/security/p5-GnuPG-Interface \
		${SITE_PERL}/Mail/Util.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/MIME/Tools.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/Convert/Recode.pm:${PORTSDIR}/converters/p5-Convert-Recode \
		${SITE_PERL}/Text/Template.pm:${PORTSDIR}/textproc/p5-Text-Template

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/:S/.orig//}

REINPLACE_ARGS=	-i ''
USE_GMAKE=	yes
USE_PERL5=	yes

SCRIPTS=	caff/caff caff/pgp-clean caff/pgp-fixkey gpglist/gpglist \
		gpgsigs/gpgsigs gpg-key2ps/gpg-key2ps \
		gpg-mailkeys/gpg-mailkeys keylookup/keylookup
MANUALS1=	${SCRIPTS:S/$/.1/}
EXAMPLES=	caff/caffrc.sample gpg-mailkeys/example.gpg-mailkeysrc

PLIST_FILES=	${SCRIPTS:T:S|^|bin/|} ${EXAMPLES:T:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	*
MAN1=		${MANUALS1:T}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/doc/signing-party/caff/caffrc\.sample|${EXAMPLESDIR}/caffrc.sample|' \
		${WRKSRC}/caff/caff
	@${REINPLACE_CMD} -e 's|/usr/bin/pinentry-gtk-2|${LOCALBASE}/bin/pinentry-gtk-2|' \
		${WRKSRC}/caff/README.gpg-agent

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
