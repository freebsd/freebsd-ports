# New ports collection makefile for: spamass-rules
# Date created:         20040802
# Whom:                 mranner@inode.at
#
# $FreeBSD$
#

PORTNAME=	rules_du_jour
PORTVERSION=	1.18
CATEGORIES=	mail
MASTER_SITES=	http://www.ranner.jawa.at/stuff/
PKGNAMEPREFIX=	spamass-

MAINTAINER=	mranner@inode.at
COMMENT=	Automatic updates of custom rulesets for SpamAssassin

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash2 \
				spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin

OPTIONS=	ANTIDRUG "Already included in SA 3.0" off \
		BOGUS_VIRUS "Catch 'collateral spam' caused by viruses" on \
		EVILNUMBERS "Phone numbers, PO boxes, ... from spam " on \
		RANDOM "Detects spamware mistakes like: %RANDOM_WORD" on \
		SARE "Installs safe SARE rules" on \
		TRIPWIRE "Matches 3 chars that shouldn't be together" off
PLIST_FILES=	bin/rules_du_jour etc/mail/rulesdujour.sample
PKGMESSAGE=		${WRKDIR}/pkg-message
NO_BUILD=		yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_DIR=	${PREFIX}/${SPAMASS_CONF}

.include <bsd.port.pre.mk>

.if defined(WITH_ANTIDRUG)
SPAMASS_FILES+=	ANTIDRUG
.endif

.if defined(WITH_BOGUS_VIRUS)
SPAMASS_FILES+=	BOGUSVIRUS
.endif

.if defined(WITH_EVILNUMBERS)
SPAMASS_FILES+=	EVILNUMBERS
.endif

.if defined(WITH_RANDOM)
SPAMASS_FILES+=	RANDOMVAL
.endif

.if defined(WITH_SARE)
.for i in SARE_ADULT SARE_FRAUD SARE_BML SARE_RATWARE SARE_SPOOF \
	SARE_BAYES_POISON_NXM SARE_OEM SARE_RANDOM SARE_SPECIFIC
SPAMASS_FILES+=	$i
.endfor
.endif

.if defined(WITH_TRIPWIRE)
SPAMASS_FILES+=	TRIPWIRE
.endif

do-build:
	@${DO_NADA}

pre-install:
	@${SED} -e 's|%%LOCALBASE%%|${PREFIX}|g' \
		-e 's|%%DOCSDIR%%|${DOCSDIR}|g' <${.CURDIR}/pkg-message >${PKGMESSAGE}
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
