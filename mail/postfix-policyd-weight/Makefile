PORTNAME=	policyd-weight
PORTVERSION=	0.1.15.2
PORTREVISION=	7
CATEGORIES=	mail
MASTER_SITES=	http://www.policyd-weight.org/releases/ \
		LOCAL/ohauer
PKGNAMEPREFIX=	postfix-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Weighted policy daemon for postfix
WWW=		https://www.policyd-weight.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-Net-DNS>=0.72:dns/p5-Net-DNS \
		p5-Net-IP>0:net-mgmt/p5-Net-IP

SUB_FILES=	pkg-message pkg-install
PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}.conf.sample" \
		share/man/man5/policyd-weight.conf.5.gz \
		share/man/man8/policyd-weight.8.gz

USERS=		polw
GROUPS=		polw

USE_RC_SUBR+=	policyd-weight
USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	${WRKSRC}/policyd-weight

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf.sample ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/man/man5/policyd-weight.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5
	${INSTALL_MAN} ${WRKSRC}/man/man8/policyd-weight.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
