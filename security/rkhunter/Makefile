# New ports collection makefile for:	rkhunter
# Date created:		15 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	rkhunter
PORTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://downloads.rootkit.nl/

MAINTAINER=	vaidab@safe-mail.net
COMMENT=	Rootkit detection tool

OPTIONS=	LSOF "Use LSOF" on \
		NMAP "Use NMAP" off

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_PERL5=	yes
NO_BUILD=	yes

MAN8=		rkhunter.8
MANCOMPRESSED=	no

PORTDOCS=	CHANGELOG README WISHLIST

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_LSOF)
RUN_DEPENDS+=	lsof:${PORTSDIR}/sysutils/lsof
.endif

.if defined(WITH_NMAP)
RUN_DEPENDS+=	nmap:${PORTSDIR}/security/nmap
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not build on sparc64
.endif

do-install:
	cd ${WRKSRC} && ./installer.sh --installdir ${PREFIX}
	${INSTALL_MAN} ${WRKSRC}/files/development/rkhunter.8 ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/files/|} ${DOCSDIR}
.endif

post-install:
	    @${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
