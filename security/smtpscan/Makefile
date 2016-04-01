# Created by: Hubert Tournier <hubert@frbsd.org>
# $FreeBSD$

PORTNAME=	smtpscan
PORTVERSION=	0.5
PORTREVISION=	2
CATEGORIES=	security mail perl5
MASTER_SITES=	PACKETSTORM/UNIX/scanners \
		http://www.frbsd.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Remote SMTP server version detector

LICENSE=	GPLv2

RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	src/smtpscan

PLIST_FILES=	bin/smtpscan \
		man/man1/smtpscan.1.gz \
		%%DATADIR%%/fingerprints \
		%%DATADIR%%/tests

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local/share|${PREFIX}/share| ; \
		 s|@VERSION@|${PORTVERSION}|' ${WRKSRC}/src/smtpscan
	@${REINPLACE_CMD} -e \
		's|@VERSION@|${PORTVERSION}| ; \
		 s|@prefix@|${PREFIX}/share|' ${WRKSRC}/docs/man/smtpscan.1

do-install:
	(cd ${WRKSRC}/src && ${INSTALL_SCRIPT} smtpscan ${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC}/docs/man \
		&& ${INSTALL_MAN} smtpscan.1 ${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && ${INSTALL_SCRIPT} fingerprints tests ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
