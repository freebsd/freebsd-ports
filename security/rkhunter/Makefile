# New ports collection makefile for:	rkhunter
# Date created:		15 May 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	rkhunter
PORTVERSION=	1.3.4
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Rootkit detection tool

OPTIONS=	LSOF "Use LSOF" on \
		NMAP "Use NMAP" off

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

USE_PERL5=	yes
NO_BUILD=	yes
SUB_FILES=	415.rkhunter

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

post-patch:
	@${REINPLACE_CMD} -e 's|{SHAREDIR}/man/man8|{PREFIX}/man/man8|g' \
		${WRKSRC}/installer.sh

do-install:
	cd ${WRKSRC} && ./installer.sh --layout custom ${PREFIX} --install
	${INSTALL_MAN} ${WRKSRC}/files/rkhunter.8 \
		${MAN8PREFIX}/man/man8
	@${MKDIR} ${PREFIX}/etc/periodic/security
	${INSTALL_SCRIPT} ${WRKDIR}/415.rkhunter ${PREFIX}/etc/periodic/security
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/files/|} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
