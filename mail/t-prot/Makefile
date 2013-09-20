# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	t-prot
PORTVERSION=	2.101
CATEGORIES=	mail
MASTER_SITES=	http://www.escape.de/~tolot/mutt/t-prot/downloads/ \
		LOCAL/sergei

MAINTAINER=	torres.g.alex@gmail.com
COMMENT=	TOFU Protection - Display Filter for RFC822 messages

RUN_DEPENDS=	p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
	p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext

USES=		perl5
NO_BUILD=	yes

MAN1=		t-prot.1
DOCS=		ChangeLog README TODO

NO_STAGE=	yes
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/t-prot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/t-prot.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
