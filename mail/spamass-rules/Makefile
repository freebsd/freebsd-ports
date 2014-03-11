# $FreeBSD$

PORTNAME=	spamass-rules
PORTVERSION=	20120817
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.eu/stuff/

MAINTAINER=	michael@ranner.eu
COMMENT=	Custom rulesets for SpamAssassin

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/spamassassin

NO_OPTIONS_SORT=	yes
OPTIONS_DEFINE=	\
	AHBL \
	AIRMAX \
	BACKHAIR \
	BOGUS_VIRUS \
	CHICKENPOX \
	CHINESE \
	DBRACKETS \
	EVILNUMBERS \
	GERMAN \
	GREEK \
	MALWARE \
	MANGLED \
	MIMEVLD \
	MSPIKE \
	NIXSPAM \
	RANDOM \
	TRIPWIRE \
	WEEDS

OPTIONS_SINGLE=		WEEDS
OPTIONS_SINGLE_WEEDS=	WEEDS1 WEEDS2
OPTIONS_DEFAULT=	BOGUS_VIRUS DBRACKETS GERMAN GREEK MALWARE MIMEVLD MSPIKE NIXSPAM RANDOM TRIPWIRE WEEDS WEEDS2

AHBL_DESC=		Check AHBL Blacklist
AIRMAX_DESC=	Some custom rulesets
BACKHAIR_DESC=	Catch those ugly, unsightly HTML tags
BOGUS_VIRUS_DESC=	Catch 'collateral spam' caused by viruses
CHICKENPOX_DESC=	Catch spam like 'l.ooks f|or th.is garb+age'
CHINESE_DESC=	Catches spam written in Chinese
DBRACKETS_DESC=		Double-brackets around To header address
EVILNUMBERS_DESC=	Phone numbers, PO boxes, ... from spam
GERMAN_DESC=	Catches spam written in German
GREEK_DESC=		Catches spam written in Greek
MALWARE_DESC=	Malware Patrol - Block List
MANGLED_DESC=	Looks for obfuscated/gappy words
MIMEVLD_DESC=	Some mime validation rules
MSPIKE_DESC=	Check mailspike.net blacklist
NIXSPAM_DESC=	Check NiX Spam blacklist
RANDOM_DESC=	Detects spamware mistakes like: %RANDOM_WORD
TRIPWIRE_DESC=	Matches 3 chars that shouldn't be together
WEEDS_DESC=		Looks at alphanum, hex, lower-, uppercase chars
WEEDS1_DESC=	Less restrictive rules
WEEDS2_DESC=	More restrictive rules

SUB_FILES=	pkg-message
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_FILES=
USE_BZIP2=	yes
INSTALL_DIR=	${PREFIX}/${SPAMASS_CONF}

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAHBL}
SPAMASS_FILES+=	20_dnsbl_ahbl.cf
.endif

.if ${PORT_OPTIONS:MAIRMAX}
SPAMASS_FILES+=	airmax.cf
.endif

.if ${PORT_OPTIONS:MBACKHAIR}
SPAMASS_FILES+=	backhair.cf
.endif

.if ${PORT_OPTIONS:MBOGUS_VIRUS}
SPAMASS_FILES+=	bogus-virus-warnings.cf
.endif

.if ${PORT_OPTIONS:MCHICKENPOX}
SPAMASS_FILES+=	chickenpox.cf
.endif

.if ${PORT_OPTIONS:MCHINESE}
SPAMASS_FILES+=	chinese_rules.cf
.endif

.if ${PORT_OPTIONS:MDBRACKETS}
SPAMASS_FILES+=	99_SMF_BRACKETS_TO.cf
.endif

.if ${PORT_OPTIONS:MEVILNUMBERS}
SPAMASS_FILES+=	evilnumbers.cf
.endif

.if ${PORT_OPTIONS:MGERMAN}
SPAMASS_FILES+=	70_zmi_german.cf
.endif

.if ${PORT_OPTIONS:MGREEK}
SPAMASS_FILES+=	gr_domain.cf
.endif

.if ${PORT_OPTIONS:MMALWARE}
SPAMASS_FILES+=	malwarepatrol.cf
.endif

.if ${PORT_OPTIONS:MMANGLED}
SPAMASS_FILES+=	mangled.cf
.endif

.if ${PORT_OPTIONS:MMIMEVLD}
SPAMASS_FILES+=	mime_validate.cf
.endif

.if ${PORT_OPTIONS:MMSPIKE}
SPAMASS_FILES+=	10_dnsbl_mspike.cf
.endif

.if ${PORT_OPTIONS:MNIXSPAM}
SPAMASS_FILES+=	20_dnsbl_nixspam.cf
.endif

.if ${PORT_OPTIONS:MRANDOM}
SPAMASS_FILES+=	random.cf
.endif

.if ${PORT_OPTIONS:MTRIPWIRE}
SPAMASS_FILES+=	99_FVGT_Tripwire.cf
.endif

.if ${PORT_OPTIONS:MWEEDS}
SPAMASS_FILES+=	weeds.cf
.endif

.if ${PORT_OPTIONS:MWEEDS2}
SPAMASS_FILES+=	weeds2.cf
.endif

PLIST_FILES=	${SPAMASS_FILES:S/^/${SPAMASS_CONF}\//}

.include <bsd.port.pre.mk>

do-build:
	@${DO_NADA}

do-install:
	@${MKDIR} ${INSTALL_DIR}
	@${INSTALL_DATA} ${SPAMASS_FILES:S/^/${WRKSRC}\//} ${INSTALL_DIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
