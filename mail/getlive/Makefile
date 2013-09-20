# Created by: ayunyan <ayunyan@gmail.com>
# $FreeBSD$

PORTNAME=	getlive
DISTVERSION=	2_7
CATEGORIES=	mail
MASTER_SITES=	http://tardisi.com/distfiles/ \
		http://lawrencechen.net/distfiles/
DISTNAME=	GetLive_${DISTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ayu@commun.jp
COMMENT=	Get mail from Hotmail (Live) mailboxes

RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		procmail:${PORTSDIR}/mail/procmail \
		p5-URI>=0:${PORTSDIR}/net/p5-URI

NO_BUILD=	yes
USES=		perl5
USE_PERL5=	run

PLIST_FILES=	bin/getlive etc/getlive.conf.sample
PORTDOCS=	ChangeLog License Manual

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/GetLive.pl ${PREFIX}/bin/getlive
	${INSTALL_DATA} ${FILESDIR}/getlive.conf.sample ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
