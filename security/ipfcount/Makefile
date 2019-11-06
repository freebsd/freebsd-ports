# Created by: Robert Archer <freebsd@deathbeforedecaf.net>
# $FreeBSD$

PORTNAME=	ipfcount
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://deathbeforedecaf.net/misc/ports/ \
		http://users.netleader.com.au/~rob/

MAINTAINER=	freebsd@deathbeforedecaf.net
COMMENT=	Summarise ipf logs by counting and sorting the fields

BROKEN=		unfetchable

PLIST_FILES=	bin/ipfcount man/man1/ipfcount.1.gz

USES=		perl5 shebangfix
SHEBANG_FILES=	ipfcount

OPTIONS_DEFINE=	EXAMPLES

PORTEXAMPLES=	100.ipfcount
SUB_FILES=	pkg-message

do-build:
	cd ${WRKSRC} && pod2man ipfcount > ipfcount.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipfcount ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipfcount.1 ${STAGEDIR}${PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/100.ipfcount ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
