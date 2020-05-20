# Created by: Larry Rosenman <ler@FreeBSD.org>
# $FreeBSD$

PORTNAME=		spamassassin-dqs
DISTVERSIONPREFIX=	v
DISTVERSION=		1.1.0
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
		etc/mail/spamassassin/sh.pre \
		share/doc/spamassassin-dqs/README.md

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	HBL
HBL_DESC=	enable HBL lookups (PAID OPTION)

HBL_PLIST_FILES=	"@sample etc/mail/spamassassin/sh_hbl.cf.sample" \
			etc/mail/spamassassin/sh_hbl_scores.cf

post-patch:
	@${REINPLACE_CMD} -e 's|<config_directory>|${PREFIX}/etc/mail/spamassassin|' ${WRKSRC}/sh.pre

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/mail/spamassassin
	${INSTALL_DATA} ${WRKSRC}/sh.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/sh.cf.sample
	${INSTALL_DATA} ${WRKSRC}/sh.pre ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${INSTALL_DATA} ${WRKSRC}/SH.pm ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${INSTALL_DATA} ${WRKSRC}/sh_scores.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN}  ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/
	

do-install-HBL-on:
	${INSTALL_DATA} ${WRKSRC}/sh_hbl.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/sh_hbl.cf.sample
	${INSTALL_DATA} ${WRKSRC}/sh_hbl_scores.cf ${STAGEDIR}${PREFIX}/etc/mail/spamassassin/

.include <bsd.port.mk>
