# Created by: chris
# $FreeBSD$

PORTNAME=	spampd
PORTVERSION=	2.42
PORTREVISION=	2
CATEGORIES=	mail perl5

MAINTAINER=	des@FreeBSD.org
COMMENT=	Spamassassin SMTP Proxy

LICENSE=	GPLv2

RUN_DEPENDS=	spamc:mail/spamassassin \
		p5-Net-Server>=0:net/p5-Net-Server

NO_BUILD=	yes
PLIST_FILES=	sbin/spampd
USES=		perl5 shebangfix
SHEBANG_FILES=	spampd.pl
SUB_LIST=	PERL=${PERL}
USE_RC_SUBR=	spampd

USE_GITHUB=	yes
GH_ACCOUNT=	mpaperno

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spampd.pl ${STAGEDIR}${PREFIX}/sbin/spampd

.include <bsd.port.mk>
