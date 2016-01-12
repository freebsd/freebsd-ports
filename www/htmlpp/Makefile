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

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}
	${INSTALL_SCRIPT} ${WRKSRC}/htmlpp ${STAGEDIR}${PREFIX}/bin/htmlpp
	${INSTALL_DATA} ${WRKSRC}/htmlpp.d ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/htmlpp.d
	(cd ${WRKSRC}; for FILE in *.pl; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${PREFIX}/${SITE_PERL_REL}/$${FILE}; done)
	(cd ${WRKSRC}; for FILE in *.def; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${PREFIX}/bin/$${FILE}; done)
	${INSTALL_DATA} ${WRKSRC}/guru_opt.fmt ${STAGEDIR}${PREFIX}/bin/guru.fmt
	(cd ${WRKSRC}; ${MKDIR} ${STAGEDIR}${DOCSDIR}; for FILE in *.htm; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)
	(cd ${WRKSRC}; for FILE in *.gif; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)
	(cd ${WRKSRC}; for FILE in *.txt; do ${INSTALL_DATA} $${FILE} ${STAGEDIR}${DOCSDIR}/$${FILE}; done)

.include <bsd.port.mk>
