# Created by: Robert Archer <freebsd@deathbeforedecaf.net>
# $FreeBSD$

PORTNAME=	ipfwcount
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://deathbeforedecaf.net/misc/ports/ \
		http://users.netleader.com.au/~rob/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Summarise ipfw logs by counting and sorting the fields

USES=		perl5

PLIST_FILES=	bin/ipfwcount man/man1/ipfwcount.1.gz
PORTEXAMPLES=	100.ipfwcount

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} -e '1s,^#![^ ]*,#!${PERL},' ${WRKSRC}/ipfwcount

do-build:
	cd ${WRKSRC} && pod2man ipfwcount > ipfwcount.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipfwcount ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipfwcount.1 ${STAGEDIR}${PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/100.ipfwcount ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
