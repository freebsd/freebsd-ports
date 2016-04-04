# Created by: trevor
# $FreeBSD$

PORTNAME=	gprename
PORTVERSION=	2.7
PORTEPOCH=	1
CATEGORIES=	x11-fm
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script for renaming multiple files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext

WRKSRC=		${WRKDIR}/${PORTNAME}/trunk

USES=		gettext perl5 tar:bzip2 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	bin/gprename
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

post-extract:
	@${RM} -rf ${WRKSRC}/build

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/local|${PREFIX}| ; \
		 s|(DESTDIR)|(DESTDIR)${PREFIX}| ; \
		 s|$$(CURDIR)|$$(.CURDIR)| ; \
		 s|uninstall build|build| ; \
		 s|share/man|man|' ${WRKSRC}/Makefile

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
