# New ports collection makefile for:	rkhunter
# Date created:		15 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	rkhunter
PORTVERSION=	1.1.4
CATEGORIES=	security
MASTER_SITES=	http://downloads.rootkit.nl/

MAINTAINER=	bugghy@SAFe-mail.net
COMMENT=	Rootkit detection tool

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5=	yes
NO_BUILD=	yes
USE_REINPLACE=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN8=		rkhunter.8
MANCOMPRESSED=	no

PORTDOCS=	CHANGELOG README WISHLIST

post-patch:
	@${SED} -e 's|PREFIX|${PREFIX}|g' ${FILESDIR}/pkg-message.in > ${PKGMESSAGE}

do-install:
	cd ${WRKSRC} && ./installer.sh --installdir ${PREFIX}
	${INSTALL_MAN} ${WRKSRC}/files/development/rkhunter.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/files/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
