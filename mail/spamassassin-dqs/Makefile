# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spamassassin-dqs
DISTVERSIONPREFIX=	v
DISTVERSION=		1.0.4
CATEGORIES=		mail

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Real-Time DNSBL's that catch a bunch of additional spam

LICENSE=	APACHE20

RUN_DEPENDS=	spamassassin:mail/spamassassin

USE_GITHUB=	yes
GH_ACCOUNT=	spamhaus

SUB_FILES=	pkg-message
PLIST_FILES=	etc/mail/spamassassin/SH.pm \
		"@sample etc/mail/spamassassin/sh.cf.sample" \
		etc/mail/spamassassin/sh_scores.cf \
		etc/mail/spamassassin/sh.pre

NO_ARCH=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|<config_directory>|${PREFIX}/etc/mail/spamassassin|' ${WRKSRC}/sh.pre

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${INSTALL_DATA} ${WRKSRC}/sh.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/sh.cf.sample
	${INSTALL_DATA} ${WRKSRC}/sh.pre ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${INSTALL_DATA} ${WRKSRC}/SH.pm ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${INSTALL_DATA} ${WRKSRC}/sh_scores.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
.include <bsd.port.mk>
