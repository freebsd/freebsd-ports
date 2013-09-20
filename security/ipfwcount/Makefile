# Created by: Robert Archer <freebsd@deathbeforedecaf.net>
# $FreeBSD$

PORTNAME=	ipfwcount
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://deathbeforedecaf.net/misc/ports/ \
		http://users.netleader.com.au/~rob/

MAINTAINER=	freebsd@deathbeforedecaf.net
COMMENT=	Summarise ipfw logs by counting and sorting the fields

PLIST_FILES=	bin/ipfwcount
MAN1=		ipfwcount.1

USES=		perl5

.if !defined(NOPORTDOCS)
PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES+=	%%EXAMPLESDIR%%/100.ipfwcount
SUB_FILES=	pkg-message
.endif

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '1s,^#![^ ]*,#!${PERL},' ${WRKSRC}/ipfwcount

do-build:
	cd ${WRKSRC} && pod2man ipfwcount > ipfwcount.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipfwcount ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipfwcount.1 ${PREFIX}/man/man1/ipfwcount.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/100.ipfwcount ${EXAMPLESDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
