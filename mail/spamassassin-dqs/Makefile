PORTNAME=		spamassassin-dqs
DISTVERSIONPREFIX=	v
DISTVERSION=		1.5.1
PORTREVISION=		1
CATEGORIES=		mail

MAINTAINER=	ler@FreeBSD.org
COMMENT=	Real-Time DNSBL's that catch a bunch of additional spam
WWW=		https://github.com/spamhaus/spamassassin-dqs/

LICENSE=	APACHE20

RUN_DEPENDS=	spamassassin:mail/spamassassin

USE_GITHUB=	yes
GH_ACCOUNT=	spamhaus

SUB_FILES=	pkg-message
PLIST_FILES=	"@sample etc/mail/spamassassin/sh.cf.sample" \
		etc/mail/spamassassin/sh_scores.cf \
		share/doc/spamassassin-dqs/README.md

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	HBL
HBL_DESC=	enable HBL lookups (PAID OPTION)

HBL_PLIST_FILES=	"@sample etc/mail/spamassassin/sh_hbl.cf.sample" \
			etc/mail/spamassassin/hbltest.sh \
			etc/mail/spamassassin/sh_hbl_scores.cf

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${INSTALL_DATA} ${WRKSRC}/4.0.0+/sh.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/sh.cf.sample
	${INSTALL_DATA} ${WRKSRC}/4.0.0+/sh_scores.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN}  ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

do-install-HBL-on:
	${INSTALL_DATA} ${WRKSRC}/4.0.0+/sh_hbl.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/sh_hbl.cf.sample
	${INSTALL_DATA} ${WRKSRC}/4.0.0+/sh_hbl_scores.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/

.include <bsd.port.mk>
