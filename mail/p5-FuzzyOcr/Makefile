# New ports collection makefile for:	FuzzyOcr
# Date Created:				2006-11-03
# Whom:					Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FuzzyOcr
DISTVERSION=	2.3b
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	mail perl5
MASTER_SITES=	http://users.own-hero.net/~decoder/${PORTNAME:L}/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for SpamAssassin which scans image attachments for spam

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm			\
		import:${PORTSDIR}/graphics/ImageMagick			\
		gocr:${PORTSDIR}/graphics/gocr				\
		gif2ps:${PORTSDIR}/graphics/libungif			\
		spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin	\
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5	\
		${SITE_PERL}/${PERL_ARCH}/String/Approx.pm:${PORTSDIR}/devel/p5-String-Approx

CONFLICTS=	p5-FuzzyOcr-devel-[0-9]*

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PORTDOCS=	FAQ samples
PORTDOCS_F=	FAQ samples/README samples/animated-gif.eml		\
		samples/corrupted-gif.eml samples/jpeg.eml samples/png.eml

SUB_FILES=	pkg-message

#-----------------------------------------------------------------------
# The plugin is installed twice: once where it should go, and once where
# it actually works from. This will hopefully be fixed at some point.
#-----------------------------------------------------------------------

SA_PLUGINDIR?=	Mail/SpamAssassin/Plugin
SA_CONFIGDIR?=	etc/mail/spamassassin

PLIST_FILES=	${SA_CONFIGDIR}/FuzzyOcr.pm				\
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr.pm		\
		%%EXAMPLESDIR%%/FuzzyOcr.cf %%EXAMPLESDIR%%/FuzzyOcr.words
PLIST_DIRS=	%%EXAMPLESDIR%%

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g'		\
	                  -e 's,/bin/grep,/usr/bin/grep,g'		\
	                  -e 's,/etc/mail,${LOCALBASE}/etc/mail,g'	\
	                  ${WRKSRC}/FuzzyOcr.??
	@${REINPLACE_CMD} -e 's,package FuzzyOcr;,package Mail::SpamAssassin::Plugin::FuzzyOcr;,'			\
	                 ${WRKSRC}/FuzzyOcr.pm
	@${REINPLACE_CMD} -e 's,loadplugin FuzzyOcr FuzzyOcr\.pm,loadplugin Mail::SpamAssassin::Plugin::FuzzyOcr,'	\
	                  ${WRKSRC}/FuzzyOcr.cf

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.pm ${SITE_PERL}/${SA_PLUGINDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.pm ${PREFIX}/${SA_CONFIGDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.cf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.words.sample ${EXAMPLESDIR}/FuzzyOcr.words

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/samples
.  for f in ${PORTDOCS_F}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.  endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
