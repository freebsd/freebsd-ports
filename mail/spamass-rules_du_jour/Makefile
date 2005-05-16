# New ports collection makefile for: spamass-rules
# Date created:         20040802
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	rules_du_jour
PORTVERSION=	1.20
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.jawa.at/stuff/
PKGNAMEPREFIX=	spamass-

MAINTAINER=	mranner@inode.at
COMMENT=	Automatic updates of custom rulesets for SpamAssassin

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
				spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS=	ANTIDRUG "Already included in SA 3.0" off \
		BLACKLIST "William Stearn's sa-blacklist" off \
		BLACKLISTU "William Stearn's URI blacklist" off \
		BOGUS_VIRUS "Catch 'collateral spam' caused by viruses" on \
		CURL "Use curl to download rule files" off \
		RANDOM "Detects spamware mistakes like: %RANDOM_WORD" on \
		SARE "Installs safe SARE rules" on \
		SARE_CODING "Ruleset for html coding abuse" off \
		SARE_HEADER "Ruleset for header abuse" off \
		SARE_SPEC "SARE Specific Ruleset" off \
		TRIPWIRE "Matches 3 chars that shouldn't be together" off
PLIST_FILES=	bin/rules_du_jour etc/mail/rulesdujour.sample
SUB_FILES=	pkg-message
NO_BUILD=		yes
USE_BZIP2=		yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_DIR=	${PREFIX}/${SPAMASS_CONF}

.include <bsd.port.pre.mk>

.if defined(WITH_ANTIDRUG)
SPAMASS_FILES+=	ANTIDRUG
.endif

.if defined(WITH_BOGUS_VIRUS)
SPAMASS_FILES+=	BOGUSVIRUS
.endif

.if defined(WITH_BLACKLIST)
SPAMASS_FILES+=	BLACKLIST
.endif

.if defined(WITH_BLACKLISTU)
SPAMASS_FILES+=	BLACKLIST_URI
.endif

.if defined(WITH_CURL)
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
.endif

.if defined(WITH_RANDOM)
SPAMASS_FILES+=	RANDOMVAL
.endif

.if defined(WITH_SARE)
.for i in SARE_ADULT SARE_FRAUD SARE_BML SARE_RATWARE SARE_SPOOF \
	SARE_BAYES_POISON_NXM SARE_OEM SARE_RANDOM SARE_SPECIFIC \
	EVILNUMBERS
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_SARE_CODING)
SPAMASS_FILES+=	SARE_CODING
.endif

.if defined(WITH_SARE_HEADER)
SPAMASS_FILES+=	SARE_HEADER
.endif

.if defined(WITH_SARE_SPEC)
SPAMASS_FILES+=	SARE_SPECIFIC
.endif

.if defined(WITH_TRIPWIRE)
SPAMASS_FILES+=	TRIPWIRE
.endif

do-build:
	@${DO_NADA}

pre-install:
	@${SED} -e 's|TRIPWIRE EVILNUMBERS SARE_RANDOM|${SPAMASS_FILES}|' \
		-e 's|PREFIX="/usr/local"|PREFIX="${PREFIX}"|' \
		<${WRKSRC}/config >${WRKSRC}/config.sample

do-install:
	@${INSTALL} -d -o root -g wheel -m 0755 ${SPAMASS_DIR}/RulesDuJour
	@${INSTALL} ${WRKSRC}/rules_du_jour ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/config.sample ${PREFIX}/etc/mail/rulesdujour.sample

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
