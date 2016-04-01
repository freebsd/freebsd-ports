# $FreeBSD$

PORTNAME=	spamass-rules
PORTVERSION=	20140707
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.eu/stuff/

MAINTAINER=	michael@ranner.eu
COMMENT=	Custom rulesets for SpamAssassin

RUN_DEPENDS=	spamc:mail/spamassassin

USES=		tar:bzip2

OPTIONS_DEFINE=	AIRMAX BACKHAIR BOGUS_VIRUS CHICKENPOX DBRACKETS \
		EVILNUMBERS MANGLED MIMEVLD RANDOM TRIPWIRE

OPTIONS_SINGLE=		WEEDS
OPTIONS_GROUP=		LANG BLACKLIST

OPTIONS_SINGLE_WEEDS=	WEEDS1 WEEDS2
WEEDS_DESC=		Looks at alphanum, hex, lower-, uppercase chars

OPTIONS_GROUP_LANG=	CHINESE GERMAN GREEK POLISH
LANG_DESC=		Catch spam written in...

OPTIONS_GROUP_BLACKLIST=AHBL MALWARE MSPIKE NIXSPAM
BLACKLIST=		DNS Blacklists

OPTIONS_DEFAULT=	BOGUS_VIRUS DBRACKETS GERMAN GREEK MALWARE MIMEVLD MSPIKE NIXSPAM POLISH RANDOM TRIPWIRE WEEDS WEEDS2

AHBL_DESC=		AHBL Blacklist
MALWARE_DESC=		Malware Patrol
MSPIKE_DESC=		mailspike.net blacklist
NIXSPAM_DESC=		NiX Spam blacklist

AIRMAX_DESC=		Some custom rulesets
BACKHAIR_DESC=		Catch those ugly, unsightly HTML tags
BOGUS_VIRUS_DESC=	Catch 'collateral spam' caused by viruses
CHICKENPOX_DESC=	Catch spam like 'l.ooks f|or th.is garb+age'
DBRACKETS_DESC=		Double-brackets around To header address
EVILNUMBERS_DESC=	Phone numbers, PO boxes, ... from spam
MANGLED_DESC=		Looks for obfuscated/gappy words
MIMEVLD_DESC=		Some mime validation rules
RANDOM_DESC=		Detects spamware mistakes like: %RANDOM_WORD
TRIPWIRE_DESC=		Matches 3 chars that shouldn't be together

CHINESE_DESC=		Chinese
GERMAN_DESC=		German
GREEK_DESC=		Greek
POLISH_DESC=		Polish

WEEDS1_DESC=		Less restrictive rules
WEEDS2_DESC=		More restrictive rules

SUB_FILES=		pkg-message
NO_BUILD=		yes
NO_WRKSUBDIR=		yes
DATADIR=		${PREFIX}/etc/mail/spamassassin

AHBL_CONF=		20_dnsbl_ahbl.cf
AIRMAX_CONF=		airmax.cf
BACKHAIR_CONF=		backhair.cf
BOGUS_VIRUS_CONF=	bogus-virus-warnings.cf
CHICKENPOX_CONF=	chickenpox.cf
CHINESE_CONF=		chinese_rules.cf
DBRACKETS_CONF=		99_SMF_BRACKETS_TO.cf
EVILNUMBERS_CONF=	evilnumbers.cf
GERMAN_CONF=		70_zmi_german.cf
GREEK_CONF=		gr_domain.cf
MALWARE_CONF=		malwarepatrol.cf
MANGLED_CONF=		mangled.cf
MIMEVLD_CONF=		mime_validate.cf
MSPIKE_CONF=		10_dnsbl_mspike.cf
NIXSPAM_CONF=		20_dnsbl_nixspam.cf
POLISH_CONF=		sa_body_test_pl.cf
RANDOM_CONF=		random.cf
TRIPWIRE_CONF=		99_FVGT_Tripwire.cf
WEEDS1_CONF=		weeds.cf
WEEDS2_CONF=		weeds2.cf

.include <bsd.port.options.mk>

.for opt in ${PORT_OPTIONS}
.  if defined(${opt}_CONF)
PLIST_FILES+=	${DATADIR_REL}/${${opt}_CONF}
.  endif
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for opt in ${PORT_OPTIONS}
.  if defined(${opt}_CONF)
	${INSTALL_DATA} ${WRKSRC}/${${opt}_CONF} ${STAGEDIR}${DATADIR}
.  endif
.endfor

.include <bsd.port.mk>
