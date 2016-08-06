# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	htmlpp
PORTVERSION=	4.2a
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://legacy.imatix.com/pub/tools/
DISTNAME=	htmlp42a

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script to allow easy creation of HTML from template files

LICENSE=	GPLv2+

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	htmlpp
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/htmlpp ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.def ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/*.pl ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/
	${INSTALL_DATA} ${WRKSRC}/htmlpp.d ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/
	${INSTALL_DATA} ${WRKSRC}/guru_opt.fmt ${STAGEDIR}${PREFIX}/bin/guru.fmt

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.htm *.gif *.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
