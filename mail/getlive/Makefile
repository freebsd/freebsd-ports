# Created by: ayunyan <ayunyan@gmail.com>
# $FreeBSD$

PORTNAME=	getlive
DISTVERSION=	3_0_3
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://tardisi.com/distfiles/ \
		http://lawrencechen.net/distfiles/
DISTNAME=	GetLive_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ayu@commun.jp
COMMENT=	Get mail from Hotmail (Live) mailboxes

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		procmail:${PORTSDIR}/mail/procmail \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-WWW-Mechanize-GZip>=0:${PORTSDIR}/www/p5-WWW-Mechanize-GZip

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	GetLive.pl
USE_PERL5=	run

PLIST_FILES=	bin/getlive etc/getlive.conf.sample
PORTDOCS=	ChangeLog License Manual

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GetLive.pl ${STAGEDIR}${PREFIX}/bin/getlive
	${INSTALL_DATA} ${FILESDIR}/getlive.conf.sample ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
