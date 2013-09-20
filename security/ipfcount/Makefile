# Created by: Robert Archer <freebsd@deathbeforedecaf.net>
# $FreeBSD$

PORTNAME=	ipfcount
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://deathbeforedecaf.net/misc/ports/ \
		http://users.netleader.com.au/~rob/

MAINTAINER=	freebsd@deathbeforedecaf.net
COMMENT=	Summarise ipf logs by counting and sorting the fields

PLIST_FILES=	bin/ipfcount
MAN1=		ipfcount.1

USES=		perl5

.if !defined(NOPORTDOCS)
PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES+=	%%EXAMPLESDIR%%/100.ipfcount
SUB_FILES=	pkg-message
.endif

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '1s,^#![^ ]*,#!${PERL},' ${WRKSRC}/ipfcount

do-build:
	cd ${WRKSRC} && pod2man ipfcount > ipfcount.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipfcount ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipfcount.1 ${PREFIX}/man/man1/ipfcount.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/100.ipfcount ${EXAMPLESDIR}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
