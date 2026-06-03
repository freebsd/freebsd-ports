PORTNAME=	spampd
PORTVERSION=	2.63
CATEGORIES=	mail perl5

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Spamassassin SMTP Proxy
WWW=		https://github.com/mpaperno/spampd

LICENSE=	GPLv3

RUN_DEPENDS=	p5-Net-Server>=0:net/p5-Net-Server \
		spamc:mail/spamassassin

USES=		perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	mpaperno
USE_RC_SUBR=	spampd

SHEBANG_FILES=	spampd.pl
NO_BUILD=	yes
SUB_LIST=	PERL=${PERL}

PLIST_FILES=	sbin/spampd

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/spampd.pl ${STAGEDIR}${PREFIX}/sbin/spampd

.include <bsd.port.mk>
