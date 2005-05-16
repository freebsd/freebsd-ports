# New ports collection makefile for: spamass-rules
# Date created:         20040725
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	spamass-rules
PORTVERSION=	20050515
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.jawa.at/stuff/ \
		http://web.inforum.at/downloads/

MAINTAINER=	mranner@inode.at
COMMENT=	Custom rulesets for SpamAssassin

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS=	AHBL "Check AHBL Blacklist" off \
		AIRMAX "Some custom rulesets" off \
		ANTIDRUG "Already included in SA 3.0" off \
		BACKHAIR "Catch those ugly, unsightly HTML tags" on \
		BOGUS_VIRUS "Catch 'collateral spam' caused by viruses" on \
		BRAZILIAN "Catches spam written in Portuguese" off \
		CHICKENPOX "Catch spam like 'l.ooks f|or th.is garb+age'" on \
		CHINESE "Catches spam written in Chinese" off \
		EVILNUMBERS "Phone numbers, PO boxes, ... from spam " on \
		FRENCH "Catches spam written in French" off \
		GERMAN "Catches spam written in German" off \
		MANGLED "Looks for obfuscated/gappy words" off \
		MIMEVLD "Some mime validation rules" off \
		RANDOM "Detects spamware mistakes like: %RANDOM_WORD" on \
		ROMANIAN "Catches spam written in Romanian" off \
		SARE "Installs safe SARE rules" on \
		SARE1 "Installs more restrictive SARE rules" off \
		SARE2 "Installs more cpu intensive SARE rules" off \
		SARE3 "Installs aggressive SARE rules" off \
		SAREH "Installs SARE high risk rules" off \
		TRIPWIRE "Matches 3 chars that shouldn't be together" off \
		WEEDS "Looks at alphanum, hex, lower-, uppercase chars" on \
		WEEDS2 "More restrictive than WEEDS, dont use together" off
SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_FILES=
USE_BZIP2=	yes
INSTALL_DIR=	${PREFIX}/${SPAMASS_CONF}

.include <bsd.port.pre.mk>

.if defined(WITH_AHBL)
SPAMASS_FILES+=	20_dnsbl_ahbl.cf
.endif

.if defined(WITH_AIRMAX)
SPAMASS_FILES+=	airmax.cf
.endif

.if defined(WITH_ANTIDRUG)
SPAMASS_FILES+=	antidrug.cf
.endif

.if !defined(WITHOUT_BACKHAIR)
SPAMASS_FILES+=	backhair.cf
.endif

.if !defined(WITHOUT_BOGUS_VIRUS)
SPAMASS_FILES+=	bogus-virus-warnings.cf
.endif

.if defined(WITH_BRAZILIAN)
.for i in 24_br_wiki_BODY.cf 24_br_wiki_HEADER.cf 24_br_wiki_META.cf \
	24_br_wiki_RAWBODY.cf 24_br_wiki_URI.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if !defined(WITHOUT_CHICKENPOX)
SPAMASS_FILES+=	chickenpox.cf
.endif

.if defined(WITH_CHINESE)
SPAMASS_FILES+=	chinese_rules.cf
.endif

.if !defined(WITHOUT_EVILNUMBERS)
SPAMASS_FILES+=	evilnumbers.cf
.endif

.if defined(WITH_FRENCH)
SPAMASS_FILES+=	french_rules.cf
.endif

.if defined(WITH_GERMAN)
.for i in 24_de_wiki_BODY.cf 24_de_wiki_HEADER.cf 24_de_wiki_URI.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_MANGLED)
SPAMASS_FILES+=	mangled.cf
.endif

.if defined(WITH_MIMEVLD)
SPAMASS_FILES+=	mime_validate.cf
.endif

.if !defined(WITHOUT_RANDOM)
SPAMASS_FILES+=	random.cf
.endif

.if defined(WITH_ROMANIAN)
SPAMASS_FILES+=	blacklist_ro.cf
.endif

.if !defined(WITHOUT_SARE)
.for i in 70_sare_adult.cf 70_sare_bayes_poison_nxm.cf 70_sare_header0.cf \
	70_sare_html0.cf 70_sare_genlsubj0.cf 70_sare_oem.cf 70_sare_obfu0.cf \
	70_sare_random.cf 70_sare_specific.cf 70_sare_spoof.cf \
	70_sare_unsub.cf 70_sare_uri.cf 72_sare_redirect_post3.0.0.cf \
	72_sare_bml_post25x.cf 99_sare_fraud_post25x.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SARE1)
.for i in 70_sare_header1.cf 70_sare_html1.cf 70_sare_genlsubj1.cf 70_sare_obfu1.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SARE2)
.for i in 70_sare_header2.cf 70_sare_html2.cf 70_sare_genlsubj2.cf 70_sare_obfu2.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SARE3)
.for i in 70_sare_header3.cf 70_sare_html3.cf 70_sare_genlsubj3.cf 70_sare_obfu3.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SAREH)
SPAMASS_FILES+=	70_sare_highrisk.cf
.endif

.if defined(WITH_TRIPWIRE)
SPAMASS_FILES+=	99_FVGT_Tripwire.cf
.endif

.if !defined(WITHOUT_WEEDS) && !defined(WITH_WEEDS2)
SPAMASS_FILES+=	weeds.cf
.endif

.if defined(WITH_WEEDS2) && defined(WITHOUT_WEEDS)
SPAMASS_FILES+=	weeds2.cf
.endif

PLIST_FILES=	${SPAMASS_FILES:S/^/${SPAMASS_CONF}\//}

do-build:
	@${DO_NADA}

do-install:
	@${MKDIR} ${INSTALL_DIR}
	@${INSTALL_DATA} ${SPAMASS_FILES:S/^/${WRKSRC}\//} ${INSTALL_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
