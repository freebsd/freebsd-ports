# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	calamaris
PORTVERSION=	2.99.4.5
CATEGORIES=	www textproc
MASTER_SITES=	http://cord.de/files/calamaris/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Perl script to produce statistics out of Squid log files

LICENSE=	GPLv2

CONFLICTS_INSTALL=	calamaris-[0-9]*

USES=		shebangfix perl5
NO_BUILD=	yes
SHEBANG_FILES=	calamaris calamaris-cache-convert

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/calamaris-cache-convert ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${INSTALL_DATA} ${WRKSRC}/calAxestype.pm ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${INSTALL_DATA} ${WRKSRC}/calAxestype3d.pm ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${INSTALL_DATA} ${WRKSRC}/calBars3d.pm ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}
	${INSTALL_DATA} ${WRKSRC}/calamaris.conf ${STAGEDIR}${PREFIX}/etc/calamaris.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/EXAMPLES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
