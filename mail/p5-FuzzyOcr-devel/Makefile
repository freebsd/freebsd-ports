# New ports collection makefile for:	FuzzyOcr
# Date Created:				2006-11-03
# Whom:					Shaun Amott <shaun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	FuzzyOcr
DISTVERSION=	3.6.0
CATEGORIES=	mail perl5
MASTER_SITES=	http://users.own-hero.net/~decoder/${PORTNAME:L}/	\
		http://mirror.inerd.com/FreeBSD/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Plugin for SpamAssassin which scans image attachments for spam

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm			\
		gifsicle:${PORTSDIR}/graphics/gifsicle			\
		gocr:${PORTSDIR}/graphics/gocr				\
		ocrad:${PORTSDIR}/graphics/ocrad			\
		gif2ps:${PORTSDIR}/graphics/libungif			\
		spamassassin:${PORTSDIR}/mail/p5-Mail-SpamAssassin	\
		${SITE_PERL}/MLDBM.pm:${PORTSDIR}/databases/p5-MLDBM	\
		${SITE_PERL}/${PERL_ARCH}/Time/HiRes.pm:${PORTSDIR}/devel/p5-Time-HiRes \
		${SITE_PERL}/MLDBM/Sync.pm:${PORTSDIR}/databases/p5-MLDBM-Sync \
		${SITE_PERL}/${PERL_ARCH}/String/Approx.pm:${PORTSDIR}/devel/p5-String-Approx

USE_PERL5=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	samples
PORTDOCS_F=	samples/README samples/ocr-animated.eml			\
		samples/ocr-gif.eml samples/ocr-jpg.eml samples/ocr-multi.eml	\
		samples/ocr-obfuscated.eml samples/ocr-png.eml samples/ocr-wrongext.eml

SUB_FILES=	pkg-message

SA_PLUGINDIR?=	Mail/SpamAssassin/Plugin
SA_CONFIGDIR?=	etc/mail/spamassassin

PLIST_FILES=	%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr.pm		\
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Config.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Deanimate.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Hashing.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Logging.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Misc.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Preprocessor.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Scanset.pm \
		%%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr/Scoring.pm \
		%%EXAMPLESDIR%%/FuzzyOcr.cf %%EXAMPLESDIR%%/FuzzyOcr.words %%EXAMPLESDIR%%/FuzzyOcr.scansets \
		%%EXAMPLESDIR%%/FuzzyOcr.preps %%EXAMPLESDIR%%/FuzzyOcr.mysql
PLIST_DIRS=	%%EXAMPLESDIR%% %%SITE_PERL%%/${SA_PLUGINDIR}/FuzzyOcr

.include <bsd.port.pre.mk>

#.if defined(WITH_OCRAD)
#RUN_DEPENDS+=	ocrad:${PORTSDIR}/graphics/ocrad
#.endif

pre-everything::
	@${ECHO_MSG} "+---------------------------------------------------+"
	@${ECHO_MSG} "|                                                   |"
	@${ECHO_MSG} "| Warning: FuzzyOcr now requires SpamAssassin 3.2.X |"
	@${ECHO_MSG} "|                                                   |"
	@${ECHO_MSG} "+---------------------------------------------------+"

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/bin,${LOCALBASE}/bin,g'		\
	                  -e 's,/etc/mail,${LOCALBASE}/etc/mail,g'	\
	                  ${WRKSRC}/FuzzyOcr.??  ${WRKSRC}/FuzzyOcr/Config.pm
	@${REINPLACE_CMD} -e 's,FuzzyOcr::,Mail::SpamAssassin::Plugin::FuzzyOcr::,'			\
	                  ${WRKSRC}/FuzzyOcr.pm ${WRKSRC}/FuzzyOcr/*.pm
	@${REINPLACE_CMD} -e 's,FuzzyOcr;,Mail::SpamAssassin::Plugin::FuzzyOcr;,'			\
	                  ${WRKSRC}/FuzzyOcr.pm

do-install:
	@${MKDIR} ${EXAMPLESDIR} ${SITE_PERL}/${SA_PLUGINDIR}/FuzzyOcr
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.pm ${SITE_PERL}/${SA_PLUGINDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr/*.pm ${SITE_PERL}/${SA_PLUGINDIR}/FuzzyOcr
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.cf ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.words ${EXAMPLESDIR}/FuzzyOcr.words
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.scansets ${EXAMPLESDIR}/FuzzyOcr.scansets
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.preps ${EXAMPLESDIR}/FuzzyOcr.preps
	${INSTALL_DATA} ${WRKSRC}/FuzzyOcr.mysql ${EXAMPLESDIR}/FuzzyOcr.mysql

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/samples
.  for f in ${PORTDOCS_F}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.  endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
