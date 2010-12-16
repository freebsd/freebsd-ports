# New ports collection makefile for:	spamass-ixhash
# Date created:		2010-11-12
# Whom:		Michael Ranner <michael@ranner.eu>
#
# $FreeBSD$
#

PORTNAME=	iXhash
PORTVERSION=	1.5.5
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	SF/ixhash/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMEPREFIX=	spamass-
EXTRACT_SUFX=	.tgz

MAINTAINER=	michael@ranner.eu
COMMENT=	The iXhash plugin for SpamAssassin

RUN_DEPENDS=	spamc:${PORTSDIR}/mail/p5-Mail-SpamAssassin \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-Net-DNS>=0.63:${PORTSDIR}/dns/p5-Net-DNS

LICENSE=	ASL
LICENSE_FILE=	${WRKSRC}/LICENSE
SUB_FILES=	pkg-message
NO_BUILD=	yes
SPAMASS_CONF=	etc/mail/spamassassin
SPAMASS_FILES=	iXhash.cf iXhash.pm
INSTALL_DIR=	${PREFIX}/${SPAMASS_CONF}

PORTDOCS=	CHANGELOG LICENSE WHERE_ARE_THE_OTHER_FILES INSTALL README
PLIST_FILES=	${SPAMASS_CONF}/iXhash.cf.sample ${SPAMASS_CONF}/iXhash.pm

post-patch:
	@${REINPLACE_CMD} -e "s,/etc/mail,${LOCALBASE}/etc/mail," \
		${WRKSRC}/iXhash/iXhash.cf

do-install:
	@${MKDIR} ${INSTALL_DIR}
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.cf ${INSTALL_DIR}/iXhash.cf.sample
	${INSTALL_DATA} ${WRKSRC}/iXhash/iXhash.pm ${INSTALL_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/
.	for i in ${PORTDOCS}
		@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.	endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
