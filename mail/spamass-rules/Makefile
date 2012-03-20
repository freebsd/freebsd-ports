# New ports collection makefile for: spamass-rules
# Date created:         20040725
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	spamass-rules
PORTVERSION=	20120319
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.eu/stuff/

MAINTAINER=	michael@ranner.eu
COMMENT=	Custom rulesets for SpamAssassin

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS=	AHBL "Check AHBL Blacklist" on \
		AIRMAX "Some custom rulesets" off \
		BACKHAIR "Catch those ugly, unsightly HTML tags" off \
		BOGUS_VIRUS "Catch 'collateral spam' caused by viruses" on \
		CHICKENPOX "Catch spam like 'l.ooks f|or th.is garb+age'" off \
		CHINESE "Catches spam written in Chinese" off \
		EVILNUMBERS "Phone numbers, PO boxes, ... from spam " off \
		GERMAN "Catches spam written in German" on \
		GREEK "Catches spam written in Greek" on \
		MALWARE "Malware Patrol - Block List" on \
		MANGLED "Looks for obfuscated/gappy words" off \
		MIMEVLD "Some mime validation rules" on \
		NIXSPAM "Check NiX Spam Blacklist" on \
		RANDOM "Detects spamware mistakes like: %RANDOM_WORD" on \
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

.if !defined(WITHOUT_CHICKENPOX)
SPAMASS_FILES+=	chickenpox.cf
.endif

.if defined(WITH_CHINESE)
SPAMASS_FILES+=	chinese_rules.cf
.endif

.if !defined(WITHOUT_EVILNUMBERS)
SPAMASS_FILES+=	evilnumbers.cf
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
