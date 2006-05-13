# New ports collection makefile for:	ipfwcount
# Date created:				22 February 2006
# Whom:					Robert Archer <freebsd@deathbeforedecaf.net>
#
# $FreeBSD$
#

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

USE_PERL5=	yes
USE_REINPLACE=	yes

.if !defined(NOPORTDOCS)
PLIST_DIRS=	%%EXAMPLESDIR%%
PLIST_FILES+=	%%EXAMPLESDIR%%/100.ipfwcount
SUB_FILES=	pkg-message
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or higher - see the lang/perl5.8 port
.endif

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

.include <bsd.port.post.mk>
