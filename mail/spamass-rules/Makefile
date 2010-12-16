# New ports collection makefile for: spamass-rules
# Date created:         20040725
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	spamass-rules
PORTVERSION=	20101112
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.eu/stuff/

MAINTAINER=	michael@ranner.eu
COMMENT=	Custom rulesets for SpamAssassin

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS=	AHBL "Check AHBL Blacklist" on \
		AIRMAX "Some custom rulesets" on \
		BACKHAIR "Catch those ugly, unsightly HTML tags" on \
		BOGUS_VIRUS "Catch 'collateral spam' caused by viruses" on \
		BRAZILIAN "Catches spam written in Portuguese" off \
		CHICKENPOX "Catch spam like 'l.ooks f|or th.is garb+age'" on \
		CHINESE "Catches spam written in Chinese" off \
		EVILNUMBERS "Phone numbers, PO boxes, ... from spam " on \
		FRENCH "Catches spam written in French" off \
		GERMAN "Catches spam written in German" on \
		GREEK "Catches spam written in Greek" on \
		MALWARE "Malware Patrol - Block List" on \
		MANGLED "Looks for obfuscated/gappy words" on \
		MIMEVLD "Some mime validation rules" on \
		NIXSPAM "Check NiX Spam Blacklist" on \
		RANDOM "Detects spamware mistakes like: %RANDOM_WORD" on \
		ROMANIAN "Catches spam written in Romanian" off \
		SARE "Installs safe SARE rules" on \
		SARE1 "Installs more restrictive SARE rules" on \
		SARE2 "Installs more cpu intensive SARE rules" on \
		SARE3 "Installs aggressive SARE rules" off \
		SAREH "Installs SARE high risk rules" off \
		SAREW "Installs SARE whitelist rules" on \
		TRIPWIRE "Matches 3 chars that shouldn't be together" on \
		WEEDS "Looks at alphanum, hex, lower-, uppercase chars" off \
		WEEDS2 "More restrictive than WEEDS, dont use together" on
SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_FILES=
USE_BZIP2=	yes
INSTALL_DIR=	${PREFIX}/${SPAMASS_CONF}

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_AHBL)
SPAMASS_FILES+=	20_dnsbl_ahbl.cf
.endif

.if !defined(WITHOUT_AIRMAX)
SPAMASS_FILES+=	airmax.cf
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

.if !defined(WITHOUT_GERMAN)
SPAMASS_FILES+=	70_zmi_german.cf
.endif

.if !defined(WITHOUT_GREEK)
SPAMASS_FILES+=	gr_domain.cf
.endif

.if !defined(WITHOUT_MALWARE)
SPAMASS_FILES+=	malwarepatrol.cf
.endif

.if !defined(WITHOUT_MANGLED)
SPAMASS_FILES+=	mangled.cf
.endif

.if !defined(WITHOUT_MIMEVLD)
SPAMASS_FILES+=	mime_validate.cf
.endif

.if !defined(WITHOUT_NIXSPAM)
SPAMASS_FILES+=	20_dnsbl_nixspam.cf
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
	70_sare_random.cf 70_sare_specific.cf 70_sare_spoof.cf 70_sare_stocks.cf \
	70_sare_unsub.cf 70_sare_uri0.cf 72_sare_redirect_post3.0.0.cf \
	72_sare_bml_post25x.cf 99_sare_fraud_post25x.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if !defined(WITHOUT_SARE1)
.for i in 70_sare_header1.cf 70_sare_html1.cf 70_sare_genlsubj1.cf 70_sare_obfu1.cf 70_sare_uri1.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if !defined(WITHOUT_SARE2)
.for i in 70_sare_header2.cf 70_sare_html2.cf 70_sare_genlsubj2.cf 70_sare_obfu2.cf 70_sare_uri2.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SARE3)
.for i in 70_sare_header3.cf 70_sare_html3.cf 70_sare_genlsubj3.cf 70_sare_obfu3.cf 70_sare_uri3.cf
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SAREH)
SPAMASS_FILES+=	70_sare_highrisk.cf
.endif

.if !defined(WITHOUT_SAREW)
SPAMASS_FILES+=	70_sare_whitelist.cf
.endif

.if !defined(WITHOUT_TRIPWIRE)
SPAMASS_FILES+=	99_FVGT_Tripwire.cf
.endif

.if defined(WITH_WEEDS) && defined(WITHOUT_WEEDS2)
SPAMASS_FILES+=	weeds.cf
.endif

.if !defined(WITHOUT_WEEDS2) && !defined(WITH_WEEDS)
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
