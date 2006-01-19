# New ports collection makefile for:	ipfcount
# Date created:				22 December 2005
# Whom:					Robert Archer <freebsd@deathbeforedecaf.net>
#
# $FreeBSD$
#

PORTNAME=	ipfcount
PORTVERSION=	0.2
CATEGORIES=	security
MASTER_SITES=	http://deathbeforedecaf.net/misc/ports/ \
		http://users.netleader.com.au/~rob/

MAINTAINER=	freebsd@deathbeforedecaf.net
COMMENT=	Summarise ipf logs by counting and sorting the fields

PLIST_FILES=	bin/ipfcount \
		%%EXAMPLESDIR%%/100.ipfcount
PLIST_DIRS=	%%EXAMPLESDIR%%

MAN1=		ipfcount.1

SUB_FILES=	pkg-message

USE_PERL5=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl 5.6 or higher - see the lang/perl5.8 port
.endif

post-patch:
	${REINPLACE_CMD} -e '1s,^#![^ ]*,#!${PERL},' ${WRKSRC}/ipfcount

do-build:
	cd ${WRKSRC} && pod2man ipfcount > ipfcount.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ipfcount ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ipfcount.1 ${PREFIX}/man/man1/ipfcount.1
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/100.ipfcount ${EXAMPLESDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
