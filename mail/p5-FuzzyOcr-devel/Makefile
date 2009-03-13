# New ports collection makefile for:	FuzzyOcr
# Date Created:				2006-11-03
# Whom:					Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FuzzyOcr
DISTVERSION=	3.4.2
PORTREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	http://users.own-hero.net/~decoder/${PORTNAME:L}/	\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:L}-${DISTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for SpamAssassin which scans image attachments for spam

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm			\
		gifsicle:${PORTSDIR}/graphics/gifsicle			\
		gocr:${PORTSDIR}/graphics/gocr				\
		gif2ps:${PORTSDIR}/graphics/libungif			\
		spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin	\
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM	\
		${SITE_PERL}/${PERL_ARCH}/String/Approx.pm:${PORTSDIR}/devel/p5-String-Approx

CONFLICTS=	p5-FuzzyOcr-[0-9]*

OPTIONS=	OCRAD	"Include optional ocrad scanning engine"	off

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	FAQ samples
PORTDOCS_F=	FAQ samples/README samples/animated-gif.eml			\
		samples/corrupted-gif.eml samples/jpeg.eml samples/png.eml	\
		samples/ocr-animated.eml

SUB_FILES=	pkg-message

SA_PLUGINDIR?=	Mail/SpamAssassin/Plugin
SA_CONFIGDIR?=	etc/mail/spamassassin

PLIST_FILES=	%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr.pm		\
		%%EXAMPLESDIR%%/FuzzyOcr.cf %%EXAMPLESDIR%%/FuzzyOcr.words
PLIST_DIRS=	%%EXAMPLESDIR%%

.include <bsd.port.pre.mk>

.if defined(WITH_OCRAD)
RUN_DEPENDS+=	ocrad:${PORTSDIR}/graphics/ocrad
.endif

pre-everything::
	@${ECHO_MSG} "+------------------------------------------------------------+"
	@${ECHO_MSG} "|                                                            |"
	@${ECHO_MSG} "| Warning: FuzzyOcr now requires SpamAssassin 3.1.4 or above |"
	@${ECHO_MSG} "|                                                            |"
	@${ECHO_MSG} "+------------------------------------------------------------+"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g'		\
	                  -e 's,/etc/mail,${LOCALBASE}/etc/mail,g'	\
	                  ${WRKSRC}/FuzzyOcr.??
	@${REINPLACE_CMD} -e 's,package FuzzyOcr;,package Mail::SpamAssassin::Plugin::FuzzyOcr;,'			\
	                  ${WRKSRC}/FuzzyOcr.pm
	@${REINPLACE_CMD} -e 's,loadplugin FuzzyOcr FuzzyOcr\.pm,loadplugin Mail::SpamAssassin::Plugin::FuzzyOcr,'	\
	                  ${WRKSRC}/FuzzyOcr.cf

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.pm ${SITE_PERL}/${SA_PLUGINDIR}
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

.include <bsd.port.post.mk>
