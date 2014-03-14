# Created by: Shaun Amott <shaun@FreeBSD.org>
# $FreeBSD$

PORTNAME=	FuzzyOcr
DISTVERSION=	3.6.0
PORTREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	http://users.own-hero.net/~decoder/${PORTNAME:L}/
PKGNAMEPREFIX=	p5-
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME:L}-${DISTVERSION}

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	Plugin for SpamAssassin which scans image attachments for spam

RUN_DEPENDS=	giftopnm:${PORTSDIR}/graphics/netpbm			\
		gifsicle:${PORTSDIR}/graphics/gifsicle			\
		gocr:${PORTSDIR}/graphics/gocr				\
		ocrad:${PORTSDIR}/graphics/ocrad			\
		gifasm:${PORTSDIR}/graphics/giflib			\
		spamassassin:${PORTSDIR}/mail/spamassassin	\
		p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM	\
		p5-MLDBM-Sync>=0:${PORTSDIR}/databases/p5-MLDBM-Sync \
		p5-String-Approx>=0:${PORTSDIR}/devel/p5-String-Approx

USES=		perl5
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

NO_STAGE=	yes
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
